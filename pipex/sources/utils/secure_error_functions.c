/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_error_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:57:17 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/02 14:12:51 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	secure_dup2(int old_fd, int new_fd, t_cmd *cmd_line)
{
	// write(2, "SECURE DUP HERE 1\n", 19);
	// ft_putnbr_fd(cmd_line->infile, 2);
	if (dup2(old_fd, new_fd) == -1)
		free_all_and_exit(cmd_line, "Error duplicating file descriptor");
	return ;
}

void	perror_and_exit(char *error_message, t_cmd *cmd_line)
{
	safe_unlink(cmd_line);
	perror(error_message);
	exit(errno);
}

void	free_all_and_exit(t_cmd *cmd_line, char *error_message)
{
	free_all_init_malloc(cmd_line);
	perror_and_exit(error_message, cmd_line);
}

char	*ft_strdup_secure(const char *src)
{
	int		length;
	int		i;
	char	*dest;

	if (!src)
		return (NULL);
	i = 0;
	length = 0;
	while (src[length] != '\0')
	{
		length++;
	}
	dest = malloc(sizeof(char) * length + 1);
	if (!dest)
		return (NULL);
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[length] = '\0';
	return (dest);
}
