#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_CHILD_PROCESSES 7

// Function to create a child process
void createChild(int child_num) {
    if (child_num > NUM_CHILD_PROCESSES) {
        exit(EXIT_SUCCESS);  // Exit if the desired number of child processes is reached
    }

    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // This code will be executed by the child process
        printf("Child process %d with PID %d, parent PID %d\n", child_num, getpid(), getppid());
        createChild(child_num + 1); // Recursively create the next child
        exit(EXIT_SUCCESS);
    } else {
        // Parent process waits for the child to finish
        wait(NULL);
    }
}

int main() {
    // Start the chain with the first child
    createChild(1);

    return 0;
}


