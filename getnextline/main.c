#include "get_next_line.h"
#include <stdio.h>

#include <fcntl.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    int i = 1;

    while((line = get_next_line(fd)))
    {
        printf("line %d => %s",i,line);
        free(line);
        i++;
    }
    // fd = open(NULL, O_RDONLY);
    // line = get_next_line(fd);
    // printf("line %d => %s",i,line);
    return (0);
}