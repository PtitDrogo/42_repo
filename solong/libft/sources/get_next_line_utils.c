/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptitdrogo <ptitdrogo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:01:49 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/09 00:23:02 by ptitdrogo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_and_exit(char *line)
{
	free(line);
	exit(EXIT_FAILURE);
}

char	*final_check(char *line)
{
	if (line[0])
		return (line);
	return (free_and_exit(line));
}
