
void    ft_coucou(void)
{
    
    static int i = 0;
    printf("%i\n", i);
    i++;
    i = 152;
}

int main(void)
{
    ft_coucou();
    ft_coucou();
    ft_coucou();
    return (0);
}