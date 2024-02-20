/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:48:31 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/20 14:58:56 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    swap_int(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
    return ;
}

int    swap(t_node *root)
{
    if (!root || listlen(root) < 2)
        return (0);
    root = get_to_last_node(root);
    swap_int(&(root->number), &(root->prev->number));
    return (1);
}
int    ss(t_node *roota, t_node *rootb)
{
    if (swap(roota) == 0)
        return (0);
    if (swap(rootb) == 0)
        return (0);
    return (1);
}

int push(t_node **from, t_node **to)
{
    t_node *current;
    t_node *node_to_add;
    
    if (!*from)
        return (0);
    current = get_to_last_node(*from);
    node_to_add = current;
    if (current->prev)
        current->prev->next = NULL;
    else if (current == *from)
        *from = NULL;
    if ((*to) == NULL)
    {
        *to = node_to_add;
        (*to)->prev = NULL;
        (*to)->next = NULL;
        return (1);
    }
    current = get_to_last_node(*to);
    current->next = node_to_add;
    node_to_add->prev = current;
    node_to_add->next = NULL;
    return (1);
}


int    rotate(t_node **root)
{
    t_node *current;
    t_node *new_root;

    if (!root || !(*root) || listlen(*root) < 2)
        return (0);
    current = get_to_last_node(*root);
    new_root = current;
    current->prev->next = NULL;
    new_root->prev = NULL;
    new_root->next = (*root);
    (*root)->prev = new_root;
    (*root) = new_root;
    return (1);
}
int    rr(t_node **roota, t_node **rootb)
{
    if (rotate(roota) == 0)
        return (0);
    if (rotate(rootb) == 0)
        return (0);
    return (1);
}


int    reverse_rotate(t_node **root)
{
    t_node *current;
    t_node *new_root;
    
    if (!(*root) || listlen(*root) < 2)
        return (0);
    (*root)->next->prev = NULL;
    new_root = (*root)->next;
    current = get_to_last_node(*root);
    current->next = (*root);
    (*root)->prev = current;
    (*root)->next = NULL;
    (*root) = new_root;
    return (1);
}
int    rrr(t_node **roota, t_node **rootb)
{
    if (reverse_rotate(roota) == 0)
        return (0);
    if (reverse_rotate(rootb) == 0)
        return (0);
    return (1);
}