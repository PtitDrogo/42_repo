/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:15:14 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/06 19:01:23 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_nbr_len(long int nbr, int base_len)
{
    int i;

    i = 0;
    if (nbr == 0)
        return (1);
    while (nbr != 0)
    {
        nbr /= base_len;
        i++;
    }
    // #include <stdio.h>
    // printf("i = %i\n", i);
    return (i);
}

