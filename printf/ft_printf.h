#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>

int ft_putncount_str(char *str);
int ft_putncount_char(char c);
size_t ft_nbr_len(long int nbr, int base_len);
int	ft_putnbr_base(int nbr, char *base);
size_t	ft_strlen(const char *s);
int	ft_putunsign_int(unsigned int nbr);

#endif