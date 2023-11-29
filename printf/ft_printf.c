/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:09:05 by tfreydie          #+#    #+#             */
/*   Updated: 2023/11/29 17:17:59 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_special_char(char c, va_list argptr);

int ft_printf(const char *text, ...)
{
	va_list argptr;
	size_t	i;
	int		size;

	if (!text)
		return (-1);
	va_start(argptr, text);
	size = 0;
	i = 0;
	while(text[i])
	{
		if (text[i] == '%')
		{	
			i++;
			size += ft_special_char(text[i], argptr);
			i++;
		}
		else
		{	
			size += ft_putncount_char(text[i]);
			i++;
		}
	}
	va_end(argptr);
	return (size);
}


static int	ft_special_char(char c, va_list argptr)
{
	if (c == 'c')
		return(ft_putncount_char(va_arg(argptr, int)));
	if (c == 's')
		return(ft_putncount_str(va_arg(argptr, char *)));
	if (c == 'p')
		return(ft_putnbr_base(va_arg(argptr, unsigned int), "0123456789"));
	if (c == 'd')
		return(ft_putnbr_base(va_arg(argptr, int), "0123456789"));
	if (c == 'i')
		return(ft_putnbr_base(va_arg(argptr, int), "0123456789"));
	if (c == 'u')
		return(ft_putunsign_int(va_arg(argptr, unsigned int)));
	if (c == 'x')
		return(ft_putnbr_base(va_arg(argptr, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return(ft_putnbr_base(va_arg(argptr, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return(ft_putncount_char('%'));
	return (ft_putncount_char('%') + ft_putncount_char(va_arg(argptr, int)));
}
int    main()
{
    #include <stdio.h>
// 	// char str[]= " ";
//     char *s2 = "Mutro abertis. Posuere libero vrius. ei o au no gatis, per gas num morreus.";

//     printf("\n");
//     printf("   %d\n", ft_printf("ft_printf char : %c\n", 'v'));
//     printf("   %d\n", printf("prinft    char : %c\n", 'v'));
//     printf("   %d\n", ft_printf("ft_printf str : %s %s %s %s %s\n", " - ", "", "4", "", s2));
//     printf("   %d\n", printf("printf    str : %s %s %s %s %s\n", " - ", "", "4", "", s2));
//     // printf("   %d\n", ft_printf("ft_printf ptr : %p", str));
//     // printf("   %d\n\n", printf("printf    ptr : %p", str));
//     printf("   %d\n", ft_printf("ft_printf inter/decimal : %d", -123456789));
//     printf("   %d\n\n", printf("printf--- inter/decimal : %d", -123456789));
    // printf("   %d\n", ft_printf("ft_printf unsigned : %u", -123456789));
    // printf("   %d\n\n", printf("printf    unsigned : %u", -123456789));
    // printf("   %d\n", ft_printf("ft_printf hexa : %x",123456789));
    // printf("   %d\n\n", printf("printf    hexa : %x",123456789));
    // printf("   %d\n", ft_printf("ft_printf HEXA : %X",123456789));
    // printf("   %d\n\n", printf("printf    HEXA : %X",123456789));
    // printf("   %d\n", ft_printf("ft_printf pourcentage : 13%%w%%%"));
	// printf("   %d\n\n", printf("printf    pourcentage : 13%%w%%%       1"));
}
