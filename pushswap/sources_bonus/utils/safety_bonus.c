/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:59:58 by ptitdrogo         #+#    #+#             */
/*   Updated: 2024/03/01 17:42:17 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	exec_two(f_one instruction, t_node **from, t_node **to, char *str)
{
	int	status;

	status = instruction(from, to);
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

int	exec_one(f_two instruction, t_node **root, t_node **to_free, char *str)
{
	int	status;

	status = instruction(root);
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
