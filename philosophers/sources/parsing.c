/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:22:13 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/03 15:11:46 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_digit(char c);

int are_args_valid(int argc, char **args)
{
	int i;
	int j;

	if (argc < 5)
	{	
		error_and_return_0("Too few arguments");
		return (0);
	}
	j = 1;
	while (j < argc)
	{
		i = 0;
		while (args[j][i])
		{
			if (!is_digit(args[j][i]))
			{	
				error_and_return_0("Invalid arguments");
				return (0);
			}
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
	return (result);
}