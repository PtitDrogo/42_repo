/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:04:32 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/05 16:52:16 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_length(char *base);
int	ft_putunsign_int(unsigned int nbr, char *base)
{
	char    digit;
	int		base_len;
	
	base_len = ft_base_length(base);
    if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base);
		ft_putnbr_base(nbr % base_len, base);
	}
	if (nbr < base_len )
		write(1, &base[nbr], 1);
    return (ft_nbr_len(nbr, base_len));
}

static int	ft_base_length(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}