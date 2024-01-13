// #include "pipex.h"
// #include <stdio.h>


// int main(int    argc, char *argv[])
// {
//     int id;
//     int processes = argc - 1;
//     int currentindex_process;
//     int i = 0
    
//     while (i > processes)
//     {
//         id = fork();

//         if (id == 0)
//         {
//             currentindex_process = argc - processes; 
//             execlp(argv[currentindex_process], argv[currentindex_process], NULL);
//             perror("execlp"); 
//             exit(EXIT_FAILURE);
//         }
//         else 
//         {
//             processes--;
//             waitpid(id, NULL, 0);
//             printf("Parent waited for any child process to finish\n");
//         }
//     }
//     printf("success !\n");
//     exit(0);
//     return (0);
// }

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int processes = argc - 1;
    int currentindex_process;
    int i = 1;

    while(i < argc) 
    {
        int id = fork();

        if (id == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (id == 0) {
            execlp(argv[i], argv[i], NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        }
        i++;
    }

    while (processes > 0) {
        int status;
        pid_t child_pid = wait(&status);
        
        if (child_pid == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }

        printf("Child process %d finished\n", child_pid);
        processes--;
    }

    printf("All child processes have finished.\n");
    return 0;
}
