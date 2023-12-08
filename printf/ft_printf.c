/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:09:05 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/08 14:56:33 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_special_char(char c, va_list argptr, int *size);

int	ft_printf(const char *text, ...)
{
	va_list	argptr;
	size_t	i;
	int		actual_size;

	va_start(argptr, text);
	actual_size = 0;
	i = 0;
	if (!text || write(1, NULL, 0) == -1)
		actual_size = -1;
	while (text[i] && actual_size != -1)
	{
		if (text[i] == '%')
		{
			i++;
			ft_special_char(text[i], argptr, &actual_size);
		}
		else
			ft_putncount_char(text[i], &actual_size);
		i++;
	}
	va_end(argptr);
	return (actual_size);
}

static void	ft_special_char(char c, va_list argptr, int *size)
{
	if (c == 'c')
		ft_putncount_char(va_arg(argptr, int), size);
	else if (c == 's')
		ft_putncount_str(va_arg(argptr, char *), size);
	else if (c == 'p')
		ft_print_ptr(va_arg(argptr, unsigned long long), size);
	else if (c == 'd')
		ft_putnbr(va_arg(argptr, int), size);
	else if (c == 'i')
		ft_putnbr(va_arg(argptr, int), size);
	else if (c == 'u')
		ft_putunsign(va_arg(argptr, unsigned int), "0123456789", size);
	else if (c == 'x')
		ft_putunsign(va_arg(argptr, unsigned int), "0123456789abcdef", size);
	else if (c == 'X')
		ft_putunsign(va_arg(argptr, unsigned int), "0123456789ABCDEF", size);
	else if (c == '%')
		ft_putncount_char('%', size);
	else if (c == '\0')
		*size = -1;
	else
	{	
		ft_putncount_char('%', size);
		ft_putncount_char(c, size);
	}
}
// int    main()
// {
//     #include <stdio.h>
//     char str[]= "aa ";
//     char *s2 = "wesh la team";

//     printf("   %d\n", ft_printf("ft_printf char : %c", 'v'));
//     printf("   %d\n\n", printf("prinft    char : %c", 'v'));
//     printf("   %d\n\n", ft_printf("ft_printf str : %s%s%s%s%s", " - ", "", "4", "", s2));
//     printf("   %d\n\n", printf("printf    str : %s%s%s%s%s", " - ", "", "4", "", s2));
//     printf("   %d\n", ft_printf("ft_printf ptr : %p", str));
//     printf("   %d\n\n", printf("printf    ptr : %p", str));
//     printf("   %d\n", ft_printf("ft_printf inter/decimal : %d", -2147483647));
//     printf("   %d\n\n", printf("printf    inter/decimal : %d", -2147483647));
//     printf("   %d\n", ft_printf("ft_printf unsigned : %u %u %u %u %u %u", 0, 2147483647, 9, -1, -0, -2147483647));
//     printf("   %d\n\n", printf("printf    unsigned : %u %u %u %u %u %u", 0, 2147483647, 9, -1, -0, -2147483647));
//     printf("   %d\n", ft_printf("ft_printf hexa : %x",-123456789));
//     printf("   %d\n\n", printf("printf    hexa : %x",-123456789));
//     printf("   %d\n", ft_printf("ft_printf HEXA : %X",-123456789));
//     printf("   %d\n\n", printf("printf    HEXA : %X",-123456789));
//     printf("   %d\n", ft_printf(""));
//     printf("   %d\n\n", printf(""));
//     printf("   %d\n", ft_printf("ft_printf pourcentage : %w %y %I"));
//     printf("   %d\n\n", printf("printf    pourcentage : %w %y %I"));
//     printf("   %d\n", ft_printf(" NULL %s NULL ", NULL));
//     printf("   %d\n\n", printf(" NULL %s NULL ", NULL));
// }
