#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    char scriptprefix[] = "/bin/bash -c";
    while (scriptprefix[i])
    {
        printf("char = %c\n", scriptprefix[i]);
        i++;
    }
    printf("char = %s\n", scriptprefix[i]);
    return 0;
}

