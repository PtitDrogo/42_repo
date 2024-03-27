/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:22:13 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/27 17:21:51 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_digit(char c);

int is_args_valid(int argc, char **args)
{
	int i;
	int j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (args[j][i])
		{
			if (!is_digit(args[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}


static int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	basic_safe_atol(const char *nptr)
{
	int		i;
	long	result;
	long	overflow_check;

	result = 0;
	i = 0;
	while (nptr[i])
	{
		overflow_check = result;
		result = (result * 10) + (nptr[i++] - '0');
		if (result < overflow_check)
			return (ATOL_ERROR);	
	}
	return ((result));
}