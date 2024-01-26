/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:40:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/26 23:46:00 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <fcntl.h>

t_command_line *init_all(int argc, char *argv[], t_command_line  *cmd_line, char **envp);
pid_t          *init_child_ids(int argc);
int            **init_fds(int **fds, t_command_line  *cmd_line);
void            close_all_pipes(t_command_line  *cmd_line);
void            secure_dup2(int old_fd, int new_fd, t_command_line  *cmd_line);
void            init_pipes(t_command_line  *cmd_line);
void            child_process(int argc, char *argv[], char **envp, t_command_line  *cmd_line, int i);
void            process_behavior(int argc, char *argv[], t_command_line  *cmd_line, int position);

int main(int argc, char *argv[], char **envp)
{
	t_command_line cmd_line;
	int i;
	if (argc < 5)
		return (perror("Not enough arguments"), 1);
	init_all(argc, argv, &cmd_line, envp);
	i = 1; 
	while (++i < argc - 1)
		child_process(argc, argv, envp, &cmd_line, i);
	i = -1;
	close_all_pipes(&cmd_line);
	while (++i < (argc - 3))
	{
		if (waitpid(cmd_line.child_ids[i], &cmd_line.status, 0) == -1)
			free_all_and_exit(&cmd_line, "error waiting for children");
	}
	free_all_init_malloc(&cmd_line);
	return (0);
}
t_command_line *init_all(int argc, char *argv[], t_command_line  *cmd_line, char **envp)
{
	cmd_line->command_number = argc - 3;
	cmd_line->infile = 0;
	cmd_line->outfile = 0;
	cmd_line->pipes = argc - 4;
	cmd_line->current_pipe = 0;
	cmd_line->current_process = 0;
	cmd_line->possible_paths = ft_split(find_env_variable(envp, "PATH="), ':'); //MALLOC
	if (!cmd_line->possible_paths[0])
		perror_and_exit("error splitting PATH");
	cmd_line->child_ids = init_child_ids(argc); //MALLOC
	if (!cmd_line->child_ids)
	{
		free_array((void **)cmd_line->possible_paths);
		perror_and_exit("error during child ids malloc");
	}
	cmd_line->commands = ft_arg_parsing(argc, argv); // MALLOC
	if (!cmd_line->commands)
	{
		free_array((void **)cmd_line->possible_paths);
		free(cmd_line->child_ids);
		perror_and_exit("error during parsing of arguments");
	}
	cmd_line->fd = init_fds(cmd_line->fd, cmd_line); // MALLOC
	if (!cmd_line->fd)
	{
		free_all_commands_n_arguments(cmd_line->commands, cmd_line->command_number);
		free_array((void **)cmd_line->possible_paths);
		free(cmd_line->child_ids);
		perror_and_exit("error during init of fd");
	}
	init_pipes(cmd_line);
	return (cmd_line);
}
pid_t   *init_child_ids(int argc)
{
	//ASSUMING NO HEREDOC HERE
	pid_t   *result = malloc(sizeof(pid_t) * (argc - 3)); 
	if (!result)
		return (NULL);   
	return (result);
}
int **init_fds(int **fds, t_command_line  *cmd_line)
{
	int i;

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

void    init_pipes(t_command_line  *cmd_line)
{
	int i;

	i = 0;
	while (i < cmd_line->pipes)
	{
		if (pipe(cmd_line->fd[i]) == -1) 
			free_all_and_exit(cmd_line, "Error during init of pipes fds array");
		i++;
	}
	return ;
}
void close_all_pipes(t_command_line  *cmd_line)
{
	int j = 0;
	while (j < cmd_line->pipes)
	{
		if (close(cmd_line->fd[j][0]) == - 1)
			free_all_and_exit(cmd_line, "Error closing file descriptor in child");
		if (close(cmd_line->fd[j][1]) == - 1)
			free_all_and_exit(cmd_line, "Error closing file descriptor in child");
		j++;
	}
	return ;
}

void secure_dup2(int old_fd, int new_fd, t_command_line  *cmd_line)
{
	if (dup2(old_fd, new_fd) == -1)
		free_all_and_exit(cmd_line, "Error duplicating file descriptor");
	return ;
}

void    child_process(int argc, char *argv[], char **envp, t_command_line  *cmd_line, int i)
{
	
	cmd_line->current_process = i - 2;
	cmd_line->child_ids[cmd_line->current_process] = fork();
	if (cmd_line->child_ids[cmd_line->current_process] == -1)
		free_all_and_exit(cmd_line, "Error forking");
	if (cmd_line->child_ids[cmd_line->current_process] == 0)
	{
		process_behavior(argc, argv, cmd_line, i);
		close_all_pipes(cmd_line);
		cmd_line->valid_path = find_valid_path(cmd_line);
		if (cmd_line->valid_path)
			execve(cmd_line->valid_path, cmd_line->commands[cmd_line->current_process], envp);
		free(cmd_line->valid_path);
		free_all_and_exit(cmd_line, "Error executing child process");
	}
	if (cmd_line->child_ids[cmd_line->current_process] > 0 && i != 2)
		cmd_line->current_pipe++;           
	return ;
}

void    process_behavior(int argc, char *argv[], t_command_line  *cmd_line, int position)
{
	if (position == 2)
	{    
		cmd_line->infile = open(argv[1], O_RDONLY);
		secure_dup2(cmd_line->infile, STDIN_FILENO, cmd_line);
		secure_dup2(cmd_line->fd[cmd_line->current_pipe][1], STDOUT_FILENO, cmd_line);
	}
	else if ((position + 1) == argc - 1)
	{    
		cmd_line->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		secure_dup2(cmd_line->outfile, STDOUT_FILENO, cmd_line);
		secure_dup2(cmd_line->fd[cmd_line->current_pipe][0], STDIN_FILENO, cmd_line);
	}
	else
	{
		secure_dup2(cmd_line->fd[cmd_line->current_pipe + 1][1], STDOUT_FILENO, cmd_line);
		secure_dup2(cmd_line->fd[cmd_line->current_pipe][0], STDIN_FILENO, cmd_line);
	}
	return ;
}
