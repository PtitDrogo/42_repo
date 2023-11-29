/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:04:32 by tfreydie          #+#    #+#             */
/*   Updated: 2023/11/29 15:57:24 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsign_int(unsigned int nbr)
{
	char    digit;
	
    if (nbr >= 10)
	{
		ft_putunsign_int(nbr / 10);
		ft_putunsign_int(nbr % 10);
	}
	if (nbr < 10)
	{	
        digit = nbr + '0';
        write(1, &digit, 1);
    }
    return (ft_nbr_len(nbr, 10));

}