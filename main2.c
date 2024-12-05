#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_get_next_line_bonus.h"

#define NUM_FILES 3

int main(void)
{
    int fds[NUM_FILES];
    char *filenames[NUM_FILES] = {"test1.txt", "test2.txt", "test3.txt"};
    char *line;
    int i, open_files;

    // Open all files
    for (i = 0; i < NUM_FILES; i++)
    {
        fds[i] = open(filenames[i], O_RDONLY);
        if (fds[i] < 0)
        {
            perror("Error opening file");
            // Close any files that were successfully opened
            while (--i >= 0)
                close(fds[i]);
            return (1);
        }
    }

    open_files = NUM_FILES;

    // Read from files in round-robin fashion
    while (open_files > 0)
    {
        for (i = 0; i < NUM_FILES; i++)
        {
            if (fds[i] != -1)
            {
                line = get_next_line(fds[i]);
                if (line)
                {
                    printf("File %s: %s", filenames[i], line);
                    free(line);
                }
                else
                {
                    // End of file reached
                    printf("Finished reading %s\n", filenames[i]);
                    close(fds[i]);
                    fds[i] = -1;
                    open_files--;
                }
            }
        }
    }

    return (0);
}

