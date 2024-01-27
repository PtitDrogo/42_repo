#include <stdlib.h>
#include <fcntl.h>


int main(void)
{
    char *test;
    test = malloc(sizeof(char) * 10);
    free(test);
    test = NULL;
    free(test);
    return (0);
}
