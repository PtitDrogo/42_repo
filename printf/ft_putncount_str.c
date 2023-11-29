/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncount_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:16:06 by tfreydie          #+#    #+#             */
/*   Updated: 2023/11/28 20:16:09 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putncount_str(char *str)
{
    if (write(1, str, ft_strlen(str)) == -1)
        return (-1);
    return (ft_strlen(str));
}
