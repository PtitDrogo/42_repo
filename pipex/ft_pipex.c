/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:40:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/20 04:03:04 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

t_command_line *init_all(int argc, char *argv[], t_command_line  *cmd_line);
int **init_fds(int **fds, t_command_line  *cmd_line);
void    free_all_fds(int i, int **fds, t_command_line  *cmd_line);
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

t_command_line *init_all(int argc, char *argv[], t_command_line  *cmd_line)
{
    int i;

    cmd_line->infile = argv[1]; //well do trivial heredoc later;
    cmd_line->outfile = argv[argc - 1];
    cmd_line->pipes = argc - 2;
    cmd_line->current_pipe = 0;
    cmd_line->current_process = 0;
    cmd_line->is_err = 0;
    cmd_line->fd = init_fds(cmd_line->fd, cmd_line);
    i = 0;    
    return (cmd_line);
}
int **init_fds(int **fds, t_command_line  *cmd_line)
{
    int i;

    i = 0;
    fds = (int **)malloc(sizeof(int *) * cmd_line->pipes);
    write(2, "hi1", 3);
    if (!fds)
    {      
        cmd_line->is_err = 1;
        return (NULL);
    }
    while (i < cmd_line->pipes)
    {
        write(2, "hi2", 3);
        fds[i] = (int *)malloc(sizeof(int) * 2);
        if (!fds[i])
        {
            free_all_fds(i, fds, cmd_line);
            cmd_line->is_err = 1;
            return (NULL);
        }
        i++;
    }
    return (fds);
}
void    free_all_fds(int i, int **fds, t_command_line  *cmd_line)
{
    while (i > 0)
    {
        i--;
        free(fds[i]);
    }
    free(fds);
    return ;
}

int main(int argc, char *argv[])
{
    t_command_line cmd_line;
    int pipes = argc - 2;
    int fd[pipes][2];
    pid_t child_ids[argc - 1];
    int i = 0;
    int current_pipe = 0;
    int current_process;
    int status;
    int is_err;
    // if (argc < 5)
    //     return (perror("Not enough arguments"), 1);
    init_all(argc, argv, &cmd_line);
    write(2, "teststruct =", 12);
    ft_putnbr_fd(cmd_line.pipes, 2);
    while (i < pipes)
    {
        if (pipe(fd[i]) == -1) 
            {
                perror("Error opening pipe");
                exit(EXIT_FAILURE);
            }
        i++;
    }
    i = 1;
    while (i < argc)
    {
        current_process = i - 1;
        child_ids[current_process] = fork();
        if (child_ids[current_process] == -1)
        {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        if (child_ids[current_process] == 0)
        {
            // write(2, "je suis le child : ", 19);
            // ft_putnbr_fd(i - 1, 2);
            // write(2, "\n", 1);
            int j = 0;
            if (i == 1)
            {    
                if (dup2(fd[current_pipe][1], STDOUT_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
                    exit(EXIT_FAILURE);
                }
                is_err = 0;
                while (j < pipes)
                {
                    if (close(fd[j][0]) == -1)
                        is_err = 1;
                    if (close(fd[j][1]) == - 1)
                        is_err = 1;
                    j++;
                }
                if (is_err)
                {
                    perror("Error closing file descriptor in child");
                    exit(EXIT_FAILURE);
                }
            }
            else if ((i + 1) == argc)
            {    
                if (dup2(fd[current_pipe][0], STDIN_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
                    exit(EXIT_FAILURE);
                }
                is_err = 0;
                while (j < pipes)
                {
                    if (close(fd[j][0]) == -1)
                        is_err = 1;
                    if (close(fd[j][1]) == - 1)
                        is_err = 1;
                    j++;
                }
                if (is_err)
                {
                    perror("Error closing file descriptor in child");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                if (dup2(fd[current_pipe + 1][1], STDOUT_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
                    exit(EXIT_FAILURE);
                }
                if (dup2(fd[current_pipe][0], STDIN_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
                    exit(EXIT_FAILURE);
                }
                is_err = 0;
                while (j < pipes)
                {
                    if (close(fd[j][0]) == -1)
                        is_err = 1;
                    if (close(fd[j][1]) == - 1)
                        is_err = 1;
                    j++;
                }
                if (is_err)
                {
                    perror("Error closing file descriptor in child");
                    exit(EXIT_FAILURE);
                }
            }
            execlp(argv[i], argv[i], NULL);
            perror("Error executing parent process");
            exit(EXIT_FAILURE);
        }
        if (child_ids[current_process] > 0)
        {
            write(2, "current pipe = ", 15);
            ft_putnbr_fd(current_pipe, 2);
            write(2, "\n", 1);
            if (i != 1)
                current_pipe++;           
        }
        i++;
    }
    i = 0;
    
    ft_putnbr_fd(child_ids[0], 2);
    write(2, "is child id\n", 12);
    ft_putnbr_fd(child_ids[1], 2);
    write(2, "is child id\n", 12);
    ft_putnbr_fd(child_ids[2], 2);
    write(2, "is child id\n", 12);
    ft_putnbr_fd(child_ids[3], 2);
    write(2, "is child id\n", 12);
    ft_putnbr_fd(child_ids[4], 2);
    write(2, "is child id\n", 12);
    write(2, "\n", 1);
    write(2, "i et argc sont egaux a ", 23);
    ft_putnbr_fd(i, 2);
    write(2, " - ", 3);
    ft_putnbr_fd(argc, 2);
    write(2, "\n", 1);
    is_err = 0;
    int j = 0;
    while (j < pipes)
    {
        if (close(fd[j][0]) == -1)
            is_err = 1;
        if (close(fd[j][1]) == - 1)
            is_err = 1;
        j++;
    }
    while (i < (argc - 1))
    {
        write(2, "JVAI ATTENDre je suis le child : ", 33);
        ft_putnbr_fd(child_ids[i], 2);
        write(2, "\n", 1);
        if (waitpid(child_ids[i], &status, 0) == -1)
        {
            perror("error waiting for children");
            exit(EXIT_FAILURE);
        }
        write(2, "j'ai attendu ", 13);
        ft_putnbr_fd(child_ids[i], 2);
        write(2, "\n", 1);
        i++;
    }
    if (is_err)
    {
        perror("Error closing file descriptor in child");
        exit(EXIT_FAILURE);
    }
    return (0);
}