/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:48:38 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/27 05:50:36 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


pid_t	*init_child_ids(int argc)
{
	pid_t	*result;

	result = malloc(sizeof(pid_t) * (argc - 3)); 
	if (!result)
		return (NULL);
	//ASSUMING NO HEREDOC HERE
	return (result);
}

int	**init_fds(int **fds, t_cmd *cmd_line)
{
	int	i;

	i = 0;
	fds = (int **)malloc(sizeof(int *) * cmd_line->pipes);
	if (!fds)
		return (NULL);
	while (i < cmd_line->pipes)
	{
		fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!fds[i])
		{
			free_array_from_index((void **)fds, i);
			return (NULL);
		}
		i++;
	}
	return (fds);
}

void	init_pipes(t_cmd *cmd_line)
{
	int	i;

	i = 0;
	while (i < cmd_line->pipes)
	{
		if (pipe(cmd_line->fd[i]) == -1)
			free_all_and_exit(cmd_line, "Error during init of pipes fds array");
		i++;
	}
	return ;
}
