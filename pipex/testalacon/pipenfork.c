#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int start, end;
    int arrsize = sizeof(arr) / sizeof(int);
    int fd[2];

    if (pipe(fd) == -1)
        return (1);
    int id = fork();
    if (id == -1)
        return (2);
    if (id == 0)
    {
        start = 0;
        end = start + arrsize / 2;
    }
    else
    {
        start = arrsize / 2;
        end = arrsize;
    }
    int sum = 0;
    int i;
    for (i = start; i < end; i++)
    {
        sum += arr[i];
    }
    printf("Calculated partial sum is %i\n", sum);

    if (id == 0)
    {
        close(fd[0]);
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    }
    else
    {
        int sumfromchild;
        close(fd[1]);
        read(fd[0], &sumfromchild, sizeof(sumfromchild));
        close(fd[0]);

        int totalsum = sum + sumfromchild;
        printf("Total sum is %i\n", totalsum);
        wait(NULL);

    }
    return (0);
}   