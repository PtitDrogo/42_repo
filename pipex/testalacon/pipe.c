#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int arg, char *argv[])
{
    //fd[0] == read;
    //fd[1] == write;
    
    int fd[2];
    if (pipe(fd) == -1)
        return (1);
    
    int id = fork();
    if (id == -1)
        return (4);
    if (id == 0)
    {
        close(fd[0]);
        int x;
        printf("Input a number :");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1);
            return (2);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1);
            return (3);
        close(fd[0]);
        printf("got from child process : %i\n", y);
    }
}
