/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncount_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:16:06 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/05 16:49:58 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putncount_str(char *str)
{
    if (!str)
    {        
        write(1, "(null)", 6);
        return(6);
    }
    if (write(1, str, ft_strlen(str)) == -1)
        return (-1);
    return (ft_strlen(str));
}
