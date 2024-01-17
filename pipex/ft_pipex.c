/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:40:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/17 18:58:18 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int pipes = argc - 2;
    int fd[pipes][2];
    pid_t child_ids[argc - 1];
    int i = 0;
    int current_pipe = 0;
    int status;
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
        child_ids[i - 1] = fork();
        if (child_ids[i - 1] == -1)
        {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        if (child_ids[i - 1] == 0)
        {
            if (i == 1)
            {    
                if (dup2(fd[current_pipe][1], STDOUT_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
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
            }
            else
            {
                if (dup2(fd[current_pipe][1], STDOUT_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
                    exit(EXIT_FAILURE);
                }
                if (dup2(fd[current_pipe][0], STDIN_FILENO) == -1)
                {
                    perror("Error duplicating file descriptor");
                    exit(EXIT_FAILURE);
                }
            }
            int j = 0;
            while (j < pipes)
            {
                if (close(fd[j][0]) == -1)
                {
                    perror("Error closing file descriptor");
                    exit(EXIT_FAILURE);
                }
                if (close(fd[j][1]) == -1)
                {
                    perror("Error closing file descriptor");
                    exit(EXIT_FAILURE);
                }
                j++;
            }
            execlp(argv[i], argv[i], NULL);
            perror("Error executing parent process");
            exit(EXIT_FAILURE);
        }
        if (child_ids[i - 1] > 0)
        {
            if (i != 1 && i + 1 != argc)
                current_pipe++;           
        }
        i++;
    }
    i = 0;
    while (i < argc - 1)
    {
        if (waitpid(child_ids[i], &status, WNOHANG) == -1)
        {
            perror("error waiting for children");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
    while (i < pipes)
    {
        if (close(fd[i][0]) == -1)
        {
            perror("Error closing file descriptor");
            exit(EXIT_FAILURE);
        }
        if (close(fd[i][1]) == - 1)
        {
            perror("Error closing file descriptor");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    return (0);
}