#include "pipex.h"
#include <stdio.h>

int main(void)
{
    // fork();
    // printf("je vens detre fork");
    // return (0);
    int id = fork();
    int number = 4;
    int *pointer = &number;
    if (id > 0)
    {
        wait(NULL);
        printf("im parent and number is = %i\n", pointer[0]);
    }

    if (id == 0)
    {
        printf("im children and number is = %i\n", pointer[0]);
        pointer[0] = 2;
        printf("im children and number is changed to = %i\n", pointer[0]);
    }
    return (0);
}