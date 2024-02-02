/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:40:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/02 14:13:15 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	**handle_script_case(char	**array);
int		count_array_size(char **array);
void	close_all_pipes(t_cmd *cmd_line);
void	secure_dup2(int old_fd, int new_fd, t_cmd *cmd_line);
void	child_process(int argc, char *argv[], char **envp, t_cmd *cmd_line, int i);
void	process_behavior(int argc, char *argv[], t_cmd *cmd_line, int position);

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		digit = n + '0';
		write(fd, &digit, 1);
		return ;
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
int	main(int argc, char *argv[], char **envp)
{
	t_cmd		cmd_line;
	int			i;
	
	cmd_line.exit_status = 0;
	if (argc < 5)
		return (perror("Not enough arguments"), 1);
	// write(2, "yo\n", 3);
	init_all(argc, argv, &cmd_line, envp);
	i = -1;
	while (++i < cmd_line.command_number)
		child_process(argc, argv, envp, &cmd_line, i);
	i = -1;
	close_all_pipes(&cmd_line);
	while (++i < cmd_line.command_number)
	{
		if (waitpid(cmd_line.child_ids[i], &cmd_line.status, 0) == -1)
			free_all_and_exit(&cmd_line, "error waiting for children");
	}
	free_all_init_malloc(&cmd_line);
	cmd_line.exit_status = cmd_line.status;
	return (WEXITSTATUS(cmd_line.status));
}

t_cmd *init_all(int argc, char *argv[], t_cmd  *cmd_line, char **envp)
{
	cmd_line->infile = 0;
	set_heredoc(argv[1], cmd_line);
	if (cmd_line->here_doc)
		here_doc(argc, argv[2], cmd_line);
	// printf("heredoc is %i\n", cmd_line->here_doc);
	cmd_line->command_number = argc - 3 - cmd_line->here_doc;
	cmd_line->outfile = 0;
	cmd_line->pipes = argc - 4 - cmd_line->here_doc;
	cmd_line->current_pipe = 0;
	cmd_line->current_process = 0;
	cmd_line->possible_paths = ft_split(find_env_variable(envp, "PATH="), ':');
	if (!cmd_line->possible_paths[0])
		perror_and_exit("error splitting PATH", cmd_line);
	cmd_line->child_ids = init_child_ids(argc);
	if (!cmd_line->child_ids)
	{
		free_array((void **)cmd_line->possible_paths);
		perror_and_exit("error during child ids malloc", cmd_line);
	}
	cmd_line->commands = ft_arg_parsing(argc, argv, cmd_line);
	if (!cmd_line->commands)
	{
		free_array((void **)cmd_line->possible_paths);
		free(cmd_line->child_ids);
		perror_and_exit("error during parsing of arguments", cmd_line);
	}
	cmd_line->fd = init_fds(cmd_line->fd, cmd_line);
	if (!cmd_line->fd)
	{
		free_all_cmds_n_args(cmd_line->commands, cmd_line->command_number);
		free_array((void **)cmd_line->possible_paths);
		free(cmd_line->child_ids);
		perror_and_exit("error during init of fd", cmd_line);
	}
	init_pipes(cmd_line);
	return (cmd_line);
}

void	close_all_pipes(t_cmd *cmd_line)
{
	int	i; 
	
	i = 0;
	while (i < cmd_line->pipes)
	{
		if (close(cmd_line->fd[i][0]) == - 1)
			free_all_and_exit(cmd_line, "Error closing fd in child");
		if (close(cmd_line->fd[i][1]) == - 1)
			free_all_and_exit(cmd_line, "Error closing fd in child");
		i++;
	}
	return ;
}

void	child_process(int argc, char *argv[], char **envp, t_cmd  *cmd, int i)
{
	cmd->current_process = i;
	cmd->child_ids[cmd->current_process] = fork();
	if (cmd->child_ids[cmd->current_process] == -1)
		free_all_and_exit(cmd, "Error forking");
	if (cmd->child_ids[cmd->current_process] == 0)
	{
		process_behavior(argc, argv, cmd, i);
		close_all_pipes(cmd);
		cmd->valid_path = find_valid_path(cmd);
		if (cmd->valid_path)
			execve(cmd->valid_path, cmd->commands[cmd->current_process], envp);
		free(cmd->valid_path);
		free_all_and_exit(cmd, "Error executing child/command not found");
	}
	if (cmd->child_ids[cmd->current_process] > 0 && i != 0)
		cmd->current_pipe++;
	return ;
}

void	process_behavior(int argc, char *argv[], t_cmd *cmd, int position)
{
	if (position == 0)
	{
		// write(2, "infile in process behavior pos = 0 is ", 39);
		// ft_putnbr_fd(cmd->infile, 2);
		// write(2, "\n", 1);
		if (!cmd->infile)
			cmd->infile = open(argv[1], O_RDONLY);
		// write(2, "which one if fucking up 1\n", 26);
		secure_dup2(cmd->infile, STDIN_FILENO, cmd);
		// write(2, "i did secure dup 1a\n", 20);
		secure_dup2(cmd->fd[cmd->current_pipe][1], STDOUT_FILENO, cmd);
		// write(2, "i did secure dup 1b\n", 20);
	}
	else if ((position + 1) == cmd->command_number)
	{
		// write(2, "which one if fucking up 2\n", 26);
		if (cmd->here_doc)
			cmd->outfile = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0777);
		else
			cmd->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
		secure_dup2(cmd->outfile, STDOUT_FILENO, cmd);
		// write(2, "i did secure dup 2a\n", 20);
		secure_dup2(cmd->fd[cmd->current_pipe][0], STDIN_FILENO, cmd);
		// write(2, "i did secure dup 2b\n", 20);
	}
	else
	{
		// write(2, "which one if fucking up 3\n", 26);
		secure_dup2(cmd->fd[cmd->current_pipe + 1][1], STDOUT_FILENO, cmd);
		secure_dup2(cmd->fd[cmd->current_pipe][0], STDIN_FILENO, cmd);
	}
	return ;
}
