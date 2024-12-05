#include <stdio.h>
#include <fcntl.h>
#include "ft_get_next_line_bonus.h"
int main()
{
    int fd = open("test.txt", O_RDONLY, 0777);
    char *line;
    line = get_next_line(fd);
     printf("line 1 = %s", line);
    
    return 0;
   

}
