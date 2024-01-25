/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OG_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:51:19 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/19 21:52:46 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        perror("Invalid number of arguments");
        exit(EXIT_FAILURE);
    }
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
        int status;
        if (waitpid(id, &status, 0) == -1)
        {
            perror("error waiting for children");
            exit(EXIT_FAILURE);
        }
        
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

