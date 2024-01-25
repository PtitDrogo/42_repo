#include "pipex.h"

int close_fds(int **fd, int pipes)
{
    int i;
    int error_happened;

    i = 0;
    error_happened = 0;
    while (i < pipes)
    {
        if (close(fd[i][0]) == -1)
            error_happened = 1;
        if (close(fd[i][1]) == - 1)
            error_happened = 1;
        i++;
    }
    return(error_happened);
}

int **make_fds(int pipes)
{
    int i;
    int **fds;
    
    i = 0;
    fds = malloc(sizeof(int *) * pipes);
    if (!fds)
        return (NULL);
    while (i < pipes)
    {
        fds[i] = malloc(sizeof(int) * 2);
        if (!fds[i])
            return (NULL); //TODO, implement a free all function;
        i++;
    }
    return (fds);
}