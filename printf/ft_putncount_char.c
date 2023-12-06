/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncount_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:15:58 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/06 19:21:33 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putncount_char(char c)
{
    if (write(1, &c, 1) == -1)
        return (-1);// this is kinda useless
    else
        return (1);        
}
