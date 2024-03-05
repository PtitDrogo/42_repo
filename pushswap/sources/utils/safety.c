/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:59:58 by ptitdrogo         #+#    #+#             */
/*   Updated: 2024/03/05 15:42:05 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	exec_two(t_one func, t_node **from, t_node **to, char *str)
{
	int	status;

	status = func(from, to);
	if (status)
	{
		if (write(1, str, ft_strlen(str)) == -1)
		{
			deallocate(*from);
			deallocate(*to);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

int	exec_one(t_two func, t_node **root, t_node **to_free, char *str)
{
	int	status;

	status = func(root);
	if (status)
	{
		if (write(1, str, ft_strlen(str)) == -1)
		{
			deallocate(*root);
			deallocate(*to_free);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

long	ft_safe_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = sign * -1;
	if (ft_isdigit(nptr[i]) == 0 || !nptr[i])
		return (ATOI_ERROR);
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		result = (result * 10) + (nptr[i++] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			return (ATOI_ERROR);
	}
	if (nptr[i] && ft_isdigit(nptr[i]) == 0)
		return (ATOI_ERROR);
	return ((long)(result * sign));
}
