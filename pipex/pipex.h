/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:31:33 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/23 19:03:39 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct s_command_line
{
    char    *infile;
	char    *outfile;
    int		here_doc;
    int     pipes;
    int     current_pipe;
    int     current_process;
    int     is_err;
    int     **fd;
    int     status;
    char    ***commands; // this isnt needed ig
    pid_t   *child_ids;
}	t_command_line;

// typedef struct s_cmd
// {
//     char    *cmd;
//     int     arg_number;
// } t_cmd;

#endif