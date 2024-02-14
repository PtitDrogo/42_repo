/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:48:31 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/14 19:04:06 by tfreydie         ###   ########.fr       */
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

void    swap(t_node *root, char *version)
{
    if (!root || listlen(root) < 2)
        return ;
    while (root->next)
        root = root->next;
    swap_int(&(root->number), &(root->prev->number));
    printf("%s\n", version);
    return ;
}
void    ss(t_node *roota, t_node *rootb)
{
    swap(roota, "");
    swap(rootb, "ss");
    return ;
}

void push(t_node **from, t_node **to, char *version)
{
    t_node *current;
    t_node *node_to_add;
    
    if (!*from)
        return ;
    current = *from;
    while (current->next)
        current = current->next;
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
        printf("%s\n", version);
        return ;
    }
    current = *to;
    while (current->next)
        current = current->next;
    current->next = node_to_add;
    node_to_add->prev = current;
    node_to_add->next = NULL;
    printf("%s\n", version);
    return ;
}


void    rotate(t_node **root, char *version)
{
    t_node *current;
    t_node *new_root;

    if (!root || !(*root) || listlen(*root) < 2)
        return ;
    current = (*root);
    while (current->next)
        current = current->next;
    new_root = current;
    current->prev->next = NULL;
    new_root->prev = NULL;
    new_root->next = (*root);
    (*root)->prev = new_root;
    (*root) = new_root;
    printf("%s\n", version);
    return ;
}
void    rr(t_node **roota, t_node **rootb)
{
    rotate(roota, "");
    rotate(rootb, "rr");
    return ;
}


void    reverse_rotate(t_node **root, char *version)
{
    t_node *current;
    t_node *new_root;
    
    if (!(*root) || listlen(*root) < 2)
        return ;
    (*root)->next->prev = NULL;
    new_root = (*root)->next;
    current = (*root);
    while (current->next)
        current = current->next;
    current->next = (*root);
    (*root)->prev = current;
    (*root)->next = NULL;
    (*root) = new_root;
    printf("%s\n", version);
    return ;
}
void    rrr(t_node **roota, t_node **rootb)
{
    reverse_rotate(roota, "");
    reverse_rotate(rootb, "rrr");
    return ;
}