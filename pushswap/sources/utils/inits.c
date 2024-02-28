/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:49:34 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/28 20:16:18 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	insert_end(t_node **root, int value);

int	init_number_list(int size, int *number_array, t_node **root)
{
	int	i;
	int	status;

	i = 0;
	while (i < size)
	{
		status = insert_end(root, number_array[i]);
		if (!status)
			return (0);
		i++;
	}
	return (1);
}

static int	insert_end(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->next = NULL;
	new_node->number = value;
	if ((*root) == NULL)
	{
		*root = new_node;
		new_node->prev = NULL;
		init_node(new_node);
		return (1);
	}
	current = *root;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
	init_node(new_node);
	return (1);
}

void	init_node(t_node *new_node)
{
	new_node->instruction = 0;
	new_node->num_of_instructions = 0;
	new_node->target_node = NULL;
}
