/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:31:33 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/25 18:02:00 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
    int     is_err;
    char    *valid_path;
    int     **fd;
    int     status;
    char    ***commands;
    pid_t   *child_ids;
}	t_command_line;

char	**ft_split(char const *s, char c);
char ***    ft_arg_parsing(int argc, char *argv[], t_command_line  *cmd_line);
t_command_line *init_all(int argc, char *argv[], t_command_line  *cmd_line, char **envp);
char * ft_env_parsing(int argc, char *argv[], char **envp, t_command_line  *cmd_line, int i);

#endif
