/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:38:39 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/04 16:14:44 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strlen(const char *s);

int	error_and_return_0(const char *err_msg)
{
	if (!err_msg)
		return (0);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	return (0);
}

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
		i++;
	return (i);
}
