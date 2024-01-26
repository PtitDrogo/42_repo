/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:31:33 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/26 23:26:46 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


typedef struct s_command_line
{
	int     infile;
	int     outfile;
	int		here_doc;
	int     pipes;
	int     current_pipe;
	int     current_process;
	char    *valid_path;
	char    **possible_paths;
	int     **fd;
	int     status;
	int     command_number;
	char    ***commands;
	pid_t   *child_ids;
}	t_command_line;

char	        **ft_split(char const *s, char c);
char            ***ft_arg_parsing(int argc, char *argv[]);
char            *find_valid_path(t_command_line  *cmd_line);
char	        *find_env_variable(char **envp, char *env_to_find);
void	        *free_all_commands_n_arguments(char ***array, int j);
void	        free_array_from_index(void **array, int j);
void            free_array(void **array);
void    		free_all_init_malloc(t_command_line  *cmd_line);
void    		perror_and_exit(char *error_message);
void    		free_all_and_exit(t_command_line  *cmd_line, char *error_message);

#endif
