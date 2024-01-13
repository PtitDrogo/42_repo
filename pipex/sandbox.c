#include "pipex.h"
#include <stdio.h>


int main(int    argc, char *argv[])
{
    int id;
    int processes = argc - 1;
    int currentindex_process;
    int i = 0
    
    while (i > processes)
    {
        id = fork();

        if (id == 0)
        {
            currentindex_process = argc - processes; 
            execlp(argv[currentindex_process], argv[currentindex_process], NULL);
            perror("execlp"); 
            exit(EXIT_FAILURE);
        }
        else 
        {
            processes--;
            waitpid(id, NULL, 0);
            printf("Parent waited for any child process to finish\n");
        }
    }
    printf("success !\n");
    exit(0);
    return (0);
}