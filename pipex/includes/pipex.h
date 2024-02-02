/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:31:33 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/02 17:30:12 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
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
	int    	**fd;
	int     status;
	int     command_number;
	char    ***commands;
	pid_t   *child_ids;
}	t_cmd;

char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char	        **ft_split(char const *s, char c);
void			secure_dup2(int old_fd, int new_fd, t_cmd *cmd_line);
t_cmd			*init_all(int argc, char *argv[], t_cmd *cmd_line, char **envp);
char            ***ft_arg_parsing(char *argv[], t_cmd *cmd_line);
char           	*find_valid_path(t_cmd  *cmd_line);
char	        *find_env_variable(char **envp, char *env_to_find);
void	        *free_all_cmds_n_args(char ***array, int j);
void	        free_array_from_index(void **array, int j);
void            free_array(void **array);
void    		free_all_init_malloc(t_cmd  *cmd_line);
void    		perror_and_exit(char *error_message, t_cmd  *cmd_line);
void    		free_all_and_exit(t_cmd  *cmd_line, char *error_message);
char			*ft_strdup_secure(const char *src);
void			set_heredoc(char *arg, t_cmd *cmd_line);
void			here_doc(char *delimiter, t_cmd *cmd_line);
void			safe_unlink(t_cmd *cmd_line);
#endif
