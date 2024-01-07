#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int id1 = fork();
    int id2 = fork();
    while (wait(NULL) != -1 || errno != ECHILD)
        printf("waited for a child to finish\n");
    if (id1 == 0)
        if (id2 == 0)
            printf("we are process y\n");
        else
            printf("we are process x\n");
    else
        if (id2 == 0)
            printf("we are process z\n");
        else
            printf("we are parent process\n");
    
    return (0);
}