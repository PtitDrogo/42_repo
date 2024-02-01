/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_error_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:57:17 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/01 18:57:08 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	secure_dup2(int old_fd, int new_fd, t_cmd *cmd_line)
{
	if (dup2(old_fd, new_fd) == -1)
		free_all_and_exit(cmd_line, "Error duplicating file descriptor");
	return ;
}

void	perror_and_exit(char *error_message, t_cmd *cmd_line)
{
	if (cmd_line->here_doc)
	{
		if (unlink(".heredoc_tmp") == -1)
		{	
			perror("failed to unlink heredoc while handling another error");
			exit(errno);
		}
	}
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
