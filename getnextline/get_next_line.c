/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:27:36 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/09 19:49:15 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char    current_array[BUFFER_SIZE];
    int i;

    i = 0;
    read(fd, current_array, 1);//we try 1 for now
    while (current_array[i])
    {
        if (current_array[i] == '\n')
        current_array[i + 1] = '\0';
        i++;
    }
    if (!current_array[i])
        return (current_array);
    else
        get_next_line(fd);
}

int main(void)
{
    #include <stdio.h>
    
    char    *current_line;
    int fd = open("test.txt", 0);
    
    current_line = get_next_line(fd);
    if (fd == -1)
        printf("Error");
    while (current_line)
    {
        printf("%s", current_line);
        current_line = get_next_line(fd);
    }
    return (0);
}