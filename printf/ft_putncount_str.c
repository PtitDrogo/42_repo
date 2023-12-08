/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncount_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:16:06 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/08 15:00:06 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s);

void	ft_putncount_str(char *str, int *size)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (!str)
		ft_putncount_str("(null)", size);
	else if (write(1, str, strlen) == -1)
		*size = -1;
	else
		*size += strlen;
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
