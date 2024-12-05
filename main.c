#include <fcntl.h>  
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> // For free()
#include "ft_get_next_line_bonus.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY); 
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) 
    {
        printf("%s", line); 
        free(line); // Free the memory allocated by get_next_line
    }

    close(fd); 
    return (0);
}

