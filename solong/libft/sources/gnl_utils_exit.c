/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:01:49 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/09 13:50:17 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_and_exit(char *line)
{
	free(line);
	exit(EXIT_FAILURE);
}

char	*final_check_exit(char *line)
{
	if (line[0])
		return (line);
	return (free_and_exit(line));
}
