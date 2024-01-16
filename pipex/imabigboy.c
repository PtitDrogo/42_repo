#include "pipex.h"
#include <stdio.h>



int main(int argc, char *argv[])
{
    int processes = argc - 1;
    int pipe_fds[processes][2];
    int i = 0;
    while (i < processes) 
    {
        if (pipe(pipe_fds[i]) == -1) 
        {
            perror("Pipe creation failed");
            //function to close all pipes HERE;
            exit(1);
        }
        i++;
    }
    i = 0;
    while (i < processes)
    {
        int child_id = fork();
        if (child_id > 0)  
            wait(NULL);
        if (child_id == 0)
        {
            dup2(pipe_fds[1], STDOUT_FILENO);
            // if (i + 1 != processes)
            //     dup2(pipe_fds[0], STDIN_FILENO);
            close(pipe_fds[0]);
            close(pipe_fds[1]);
            execlp(argv[i + 1], argv[i + 1], NULL);
        }
        return (0);
        i++;
    }
}
    // dup2(fd[0], STDIN_FILENO);
    //         close(fd[0]);
    //         close(fd[1]);
    //         execlp(argv[2], argv[2], NULL);