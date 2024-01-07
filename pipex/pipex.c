/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:51:19 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/07 18:29:43 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    //fd[0] == read;
    //fd[1] == write;
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    int id = fork();
    if (id == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    if (id == 0)
    {
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
        execlp(argv[1], argv[1], NULL);
        //this code below only execute if exec fails
        perror("Error executing parent process");
        exit(EXIT_FAILURE);
    }
    else
    {
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
        execlp(argv[2], argv[2], NULL);
        //this code below only execute if exec fails
        perror("Error executing parent process");
        exit(EXIT_FAILURE);
    }
}