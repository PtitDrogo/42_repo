#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(void)
{
    if (mkfifo("myfifo1", 0777) == -1)
        {
            if (errno != EEXIST)
            {    
                printf("error creating fifo, and its not because it exists\n");
                return (1);
            }
        }
    printf("Opening ...\n");
    int fd = open("myfifo1", O_WRONLY);
    if (fd == -1)
        return (3);
    printf("Opened\n");
    //fifo have to be open on two end otherwise it just waits;
    int x = 'Z';
    if (write(fd, &x, sizeof(x)) == -1)
        return (2);
    close (fd);
    return (0);
}
