/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:31:33 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/07 20:13:57 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_ptr_len(unsigned long long ptr, int base_len);
static int ft_recursive_print(unsigned long long ptr);

int ft_print_ptr(unsigned long long ptr)
{
    if (ptr == 0)
        return (ft_putncount_str("(nil)"));
    else
        return(ft_putncount_str("0x") + ft_recursive_print(ptr));
}


static int ft_ptr_len(unsigned long long ptr, int base_len)
{
    int i;

    i = 0;
    if (ptr == 0)
        return (1);
    while (ptr != 0)
    {
        ptr /= base_len;
        i++;
    }
    return (i);
}

static int ft_recursive_print(unsigned long long ptr)
{
	int size;
    char *base; 
    
    base = "0123456789abcdef";
    size = 0;
    if (ptr >= 16)
	{
		ft_recursive_print(ptr / 16);
		ft_recursive_print(ptr % 16);
	}
	if (ptr < 16 )
        write(1, &base[ptr], 1);
	return (ft_ptr_len(ptr, 16));
}