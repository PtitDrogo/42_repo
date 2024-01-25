/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:51:19 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/16 16:25:03 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>


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
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int *pointer_switch;
    int int_switch = 1;
    pointer_switch = &int_switch;
    int i = 1;
    while (i < argc)
    {
        int id = fork();
        write(1, "je vens detre fork\n", 19);
        //this is getting printed only once for some reason;
        if (id == -1)
        {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        if (id > 0)
        {    
            write(1, "jattend\n", 8);
            wait(NULL);
            write(1, "jattend plus\n", 13);
        }
        else if (id == 0 && *pointer_switch == 1)
        {
            write(1, "im in1\n", 7);
            write(1, "Sp =", 4);
            ft_putnbr_fd(*pointer_switch, 1);
            write(1, "\n", 1);
            
            *pointer_switch = 0;
            write(1, "p =", 3);
            ft_putnbr_fd(*pointer_switch, 1);
            write(1, "\n", 1);
            if (dup2(fd[1], STDOUT_FILENO) == -1)
            {
                perror("Error duplicating file descriptor");
                exit(EXIT_FAILURE);
            }
            if (close(fd[0]) == -1)
            {
                perror("Error closing file descriptor");
                exit(EXIT_FAILURE);
            }
            if (close(fd[1]) == -1)
            {
                perror("Error closing file descriptor");
                exit(EXIT_FAILURE);
            }
            execlp(argv[i], argv[i], NULL);
            //this code below only execute if exec fails
            perror("Error executing parent process");
            exit(EXIT_FAILURE);
        }
        else if (id == 0 && *pointer_switch == 0)
        {
            write(1, "im in2\n", 7);
            *pointer_switch = 1;
            write(1, "p =", 3);
            ft_putnbr_fd(*pointer_switch, 1);
            write(1, "\n", 1);
            if (dup2(fd[0], STDIN_FILENO) == -1)
            {
                perror("Error duplicating file descriptor");
                exit(EXIT_FAILURE);
            }
            if (close(fd[0]) == -1)
            {
                perror("Error closing file descriptor");
                exit(EXIT_FAILURE);
            }
            if (close(fd[1]) == -1)
            {
                perror("Error closing file descriptor");
                exit(EXIT_FAILURE);
            }
            execlp(argv[i], argv[i], NULL);
            //this code below only execute if exec fails
            perror("Error executing parent process");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    //I close the fd of the parents at the very end;
    if (close(fd[0]) == -1)
    {
        perror("Error closing file descriptor");
        exit(EXIT_FAILURE);
    }
    if (close(fd[1]) == -1)
    {
        perror("Error closing file descriptor");
        exit(EXIT_FAILURE);
    }
    return (0);
}


