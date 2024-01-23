/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:40:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/23 14:10:07 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

t_command_line *init_all(int argc, char *argv[], t_command_line  *cmd_line);
pid_t          *init_child_ids(int argc, t_command_line  *cmd_line);
int            **init_fds(int **fds, t_command_line  *cmd_line);
void           free_all_fds(int index, int **fds);


void	       ft_putnbr_fd(int n, int fd)
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
    cmd_line->child_ids = init_child_ids(argc, cmd_line);
    i = 0;   
    return (cmd_line);
}
pid_t   *init_child_ids(int argc, t_command_line  *cmd_line)
{
    //ASSUMING NO HEREDOC HERE
    pid_t   *result = malloc(sizeof(pid_t) * (argc - 1)); //CHANGE THIS HERE WHEN INTRODUCING FILES
    if (!result)
    {
        cmd_line->is_err = 1;
        return (NULL);   
    }
    return (result);
}
int **init_fds(int **fds, t_command_line  *cmd_line)
{
    int i;

    i = 0;
    fds = (int **)malloc(sizeof(int *) * cmd_line->pipes);
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
            free_all_fds(i, fds);
            cmd_line->is_err = 1;
            return (NULL);
        }
        i++;
    }
    return (fds);
}
void    free_all_fds(int index, int **fds)
{
    while (index > 0)
    {
        index--;
        free(fds[index]);
    }
    free(fds);
    return ;
}

int main(int argc, char *argv[])
{
    t_command_line cmd_line;
    int i = 0;
    // if (argc < 5)
    //     return (perror("Not enough arguments"), 1);
    init_all(argc, argv, &cmd_line);
    if (cmd_line.is_err)
        return(perror("error during initialization"),  1);
    // write(2, "teststruct =", 12);
    // ft_putnbr_fd(cmd_line.pipes, 2);
    while (i < cmd_line.pipes)
    {
        if (pipe(cmd_line.fd[i]) == -1) 
            {
                perror("Error opening pipe");
                exit(EXIT_FAILURE);
            }
        i++;
    }
    i = 1;
    while (i < argc)
    {
        cmd_line.current_process = i - 1;
        cmd_line.child_ids[cmd_line.current_process] = fork();
        if (cmd_line.child_ids[cmd_line.current_process] == -1)
        {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        if (cmd_line.child_ids[cmd_line.current_process] == 0)
        {
            // write(2, "je suis le child : ", 19);
            // ft_putnbr_fd(i - 1, 2);
            // write(2, "\n", 1);
            int j = 0;
            if (i == 1)
            {    
                if (dup2(cmd_line.fd[cmd_line.current_pipe][1], STDOUT_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
                    exit(EXIT_FAILURE);
                }
                cmd_line.is_err = 0;
                while (j < cmd_line.pipes)
                {
                    if (close(cmd_line.fd[j][0]) == -1)
                        cmd_line.is_err = 1;
                    if (close(cmd_line.fd[j][1]) == - 1)
                        cmd_line.is_err = 1;
                    j++;
                }
                if (cmd_line.is_err)
                {
                    perror("Error closing file descriptor in child");
                    exit(EXIT_FAILURE);
                }
            }
            else if ((i + 1) == argc)
            {    
                if (dup2(cmd_line.fd[cmd_line.current_pipe][0], STDIN_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
                    exit(EXIT_FAILURE);
                }
                cmd_line.is_err = 0;
                while (j < cmd_line.pipes)
                {
                    if (close(cmd_line.fd[j][0]) == -1)
                        cmd_line.is_err = 1;
                    if (close(cmd_line.fd[j][1]) == - 1)
                        cmd_line.is_err = 1;
                    j++;
                }
                if (cmd_line.is_err)
                {
                    perror("Error closing file descriptor in child");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                if (dup2(cmd_line.fd[cmd_line.current_pipe + 1][1], STDOUT_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
                    exit(EXIT_FAILURE);
                }
                if (dup2(cmd_line.fd[cmd_line.current_pipe][0], STDIN_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
                    exit(EXIT_FAILURE);
                }
                cmd_line.is_err = 0;
                while (j < cmd_line.pipes)
                {
                    if (close(cmd_line.fd[j][0]) == -1)
                        cmd_line.is_err = 1;
                    if (close(cmd_line.fd[j][1]) == - 1)
                        cmd_line.is_err = 1;
                    j++;
                }
                if (cmd_line.is_err)
                {
                    perror("Error closing file descriptor in child");
                    exit(EXIT_FAILURE);
                }
            }
            execlp(argv[i], argv[i], NULL);
            perror("Error executing parent process");
            exit(EXIT_FAILURE);
        }
        write(2, "current pipe = ", 15);
        ft_putnbr_fd(cmd_line.current_pipe, 2);
        write(2, "\n", 1);
        if (cmd_line.child_ids[cmd_line.current_process] > 0 && i != 1)
            cmd_line.current_pipe++;           
        i++;
    }
    
    i = 0;
    // ft_putnbr_fd(cmd_line.child_ids[0], 2);
    // write(2, "is child id\n", 12);
    // ft_putnbr_fd(cmd_line.child_ids[1], 2);
    // write(2, "is child id\n", 12);
    // ft_putnbr_fd(cmd_line.child_ids[2], 2);
    // write(2, "is child id\n", 12);
    // ft_putnbr_fd(cmd_line.child_ids[3], 2);
    // write(2, "is child id\n", 12);
    // ft_putnbr_fd(cmd_line.child_ids[4], 2);
    // write(2, "is child id\n", 12);
    // write(2, "\n", 1);
    // write(2, "i et argc sont egaux a ", 23);
    // ft_putnbr_fd(i, 2);
    // write(2, " - ", 3);
    // ft_putnbr_fd(argc, 2);
    // write(2, "\n", 1);
    int j = 0;
    while (j < cmd_line.pipes)
    {
        if (close(cmd_line.fd[j][0]) == -1)
            cmd_line.is_err = 1;
        if (close(cmd_line.fd[j][1]) == - 1)
            cmd_line.is_err = 1;
        j++;
    }
    while (i < (argc - 1))
    {
        write(2, "JVAI ATTENDre je suis le child : ", 33);
        ft_putnbr_fd(cmd_line.child_ids[i], 2);
        write(2, "\n", 1);
        if (waitpid(cmd_line.child_ids[i], &cmd_line.status, 0) == -1)
        {
            perror("error waiting for children");
            exit(EXIT_FAILURE);
        }
        write(2, "j'ai attendu ", 13);
        ft_putnbr_fd(cmd_line.child_ids[i], 2);
        write(2, "\n", 1);
        i++;
    }
    if (cmd_line.is_err)
        return (perror("error happened"), 1); //TODO - error recognition
    free_all_fds(cmd_line.pipes, cmd_line.fd); //using pipes here might be wrong
    free(cmd_line.child_ids); 
    return (0);
}