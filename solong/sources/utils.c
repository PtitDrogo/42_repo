/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:43:39 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/13 14:08:00 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_char_correct(char c)
{
	if (c == '1')
		return (1);
	if (c == 'P')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'C')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

void	process_char(char c, int items[3])
{
	if (c == 'C')
		(items[0])++;
	else if (c == 'E')
		(items[1])++;
	else if (c == 'P')
		(items[2])++;
	return ;
}

void	perror_and_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}
