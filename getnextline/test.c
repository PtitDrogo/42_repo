
void    ft_coucou(void)
{
    static char		buffer[10];
}

#include <stdio.h>
int main(void)
{
    static char		buffer[10];
    int i = 0;

    while (i <= 10)
    {
        printf("%i", buffer[i]);
        i++;
    }
    return (0);
}