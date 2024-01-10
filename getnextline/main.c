/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:47:49 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/03 17:51:56 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#include <fcntl.h>

int main()
{
    int fd = open("test.txt", O_CREAT | O_RDONLY);
    char *line;
    int i = 1;
    // line = get_next_line(fd);
    printf("%s\n", get_next_line(fd));
    // while((line = get_next_line(fd)))
    // {
    //     printf("line %d => %s",i,line);
    //     free(line);
    //     i++;
    // }
    // fd = open(NULL, O_RDONLY);
    // line = get_next_line(fd);
    // printf("line %d => %s",i,line);
    return (0);
}
