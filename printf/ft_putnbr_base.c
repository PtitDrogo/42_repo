/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:15:44 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/05 16:51:58 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_length(char *base);

int	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	long long	real_nbr;

	real_nbr = nbr;
	base_len = ft_base_length(base);
	if (real_nbr < 0)
	{
		real_nbr = real_nbr * -1;
		write(1, "-", 1);
	}
	if (real_nbr >= base_len)
	{
		ft_putnbr_base(real_nbr / base_len, base);
		ft_putnbr_base(real_nbr % base_len, base);
	}
	if (real_nbr < base_len )
		write(1, &base[real_nbr], 1);
	return (ft_nbr_len(nbr, base_len) + (nbr < 0));
}
static int	ft_base_length(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

/*
int	main(void)
{
	char	base[] = "01";
	ft_putnbr_base(-42, base);
}*/
