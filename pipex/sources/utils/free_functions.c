/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:40:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/27 03:23:43 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array_from_index(void **array, int j)
{
	while (j > 0)
	{
		j--;
		if (array[j])
			free(array[j]);
	}
	free(array);
	return ;
}
void	*free_all_commands_n_arguments(char ***array, int j)
{
	int i;

	while (j > 0)
	{
		i = 0;
		j--;
		if (array[j])
		{
			while (array[j][i])
			{
				free(array[j][i]);
				i++;
			}
		}
		free(array[j]);
	}
	free(array);
	return (NULL);
}


void    free_array(void **array)
{
    int j;
    
    j = 0;
    while (array[j])
    {
        if (array[j])
            free(array[j]);
        j++;
    }
    free(array);
}

void    free_all_init_malloc(t_command_line  *cmd_line)
{
    free_array_from_index((void **)cmd_line->fd, cmd_line->pipes);
	free_array((void **)cmd_line->possible_paths);
	free(cmd_line->child_ids);
	free_all_commands_n_arguments(cmd_line->commands, cmd_line->command_number);
    return ;
}

void    perror_and_exit(char *error_message)
{
    perror(error_message);
    exit(errno);
}

void    free_all_and_exit(t_command_line  *cmd_line, char *error_message)
{
    free_all_init_malloc(cmd_line);
    perror_and_exit(error_message);
}