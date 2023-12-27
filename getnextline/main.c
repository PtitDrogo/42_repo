/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:47:49 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/27 13:55:02 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#include <fcntl.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    int i = 1;

    while((line = get_next_line(fd)))
    {
        printf("line %d => %s",i,line);
        free(line);
        i++;
    }
    // fd = open(NULL, O_RDONLY);
    // line = get_next_line(fd);
    // printf("line %d => %s",i,line);
    return (0);
}
