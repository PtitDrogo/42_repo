/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   propre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:40:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/20 00:03:40 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

//THE LOGIC FOR THE MIDDLE PIPES IS WRONG AND A SIMPLE +1 
//DOESNT FIX IT IMMEDIATELY VERY SAD
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

int main(int argc, char *argv[])
{
    int pipes = argc - 2;
    int fd[pipes][2];
    pid_t child_ids[argc - 1];
    int i = 0;
    int current_pipe = 0;
    int current_process;
    int status;
    int error_happened;
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
                error_happened = 0;
                while (j < pipes)
                {
                    if (close(fd[j][0]) == -1)
                        error_happened = 1;
                    if (close(fd[j][1]) == - 1)
                        error_happened = 1;
                    j++;
                }
                if (error_happened)
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
                error_happened = 0;
                while (j < pipes)
                {
                    if (close(fd[j][0]) == -1)
                        error_happened = 1;
                    if (close(fd[j][1]) == - 1)
                        error_happened = 1;
                    j++;
                }
                if (error_happened)
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
                error_happened = 0;
                while (j < pipes)
                {
                    if (close(fd[j][0]) == -1)
                        error_happened = 1;
                    if (close(fd[j][1]) == - 1)
                        error_happened = 1;
                    j++;
                }
                if (error_happened)
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
    error_happened = 0;
    int j = 0;
    while (j < pipes)
    {
        if (close(fd[j][0]) == -1)
            error_happened = 1;
        if (close(fd[j][1]) == - 1)
            error_happened = 1;
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
    if (error_happened)
    {
        perror("Error closing file descriptor in child");
        exit(EXIT_FAILURE);
    }
    return (0);
}