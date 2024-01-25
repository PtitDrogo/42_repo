#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *arr[] = {
        "echo",
        "More text",
        ">>",
        "filename.txt",
        NULL
    };
    char *env[] = {
        "HOME=/", 
        "PATH=/bin", 
        NULL
    };
    execve(
        "/usr/bin/ls", 
        arr,
        env
    );

    int err = errno;
    return (0);
}