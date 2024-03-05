/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:59:58 by ptitdrogo         #+#    #+#             */
/*   Updated: 2024/03/05 14:39:25 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

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
void	free_input_and_error_exit(t_node *roota, t_node *rootb, char *input)
{
	free(input);
	deallocate(roota);
	deallocate(rootb);
	error_message_exit();
}

