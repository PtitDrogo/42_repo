/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freenerror_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:40:18 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/10 01:42:16 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void deallocate(t_node *root)
{
    t_node *memory_to_free;
    
    while (root)
    {
        memory_to_free = root;
        root = root->next;
        free(memory_to_free);
    }
    return ;
}

void    free_all_and_exit(t_node *roota, t_node *rootb)
{
    deallocate(roota);
    deallocate(rootb);
    error_message_exit();
}

void    error_message_exit()
{
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

int listlen(t_node *root)
{
    int i;
    
    i = 0;
    while (root)
    {
        root = root->next;
        i++;
    }
    return (i);
}