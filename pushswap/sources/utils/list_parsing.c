/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 03:21:27 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/27 23:42:51 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


t_node  *get_to_last_node(t_node *root)
{
    if (!root)
        return NULL;
    while(root->next)
        root = root->next;
    return (root);
}

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
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

int is_sorted(const t_node *heada)
{
	int i;
	t_node  *current;

	current = (t_node *)heada;
	i = INT_MIN;
	
	while (current)
	{
		if (current->number < i)
			return (0);
		i = current->number;
		current = current->next; 
	}
	return (1);
}
