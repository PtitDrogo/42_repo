/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:48:31 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/28 20:03:37 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	swap(t_node **head)
{
	t_node	*new_head_node;
	t_node	*old_head;

	if (!head || listlen(*head) < 2)
		return (0);
	new_head_node = (*head)->next;
	old_head = (*head);
	old_head->next = new_head_node->next;
	old_head->prev = new_head_node;
	if (new_head_node->next)
		new_head_node->next->prev = old_head;
	new_head_node->next = old_head;
	new_head_node->prev = NULL;
	(*head) = new_head_node;
	return (1);
}

int	push(t_node **from, t_node **to)
{
	t_node	*node_to_add;

	if (*from == NULL)
		return (0);
	node_to_add = (*from);
	if ((*from)->next)
	{
		(*from)->next->prev = NULL;
		(*from) = (*from)->next;
	}
	else
		(*from) = NULL;
	if ((*to) == NULL)
	{
		*to = node_to_add;
		(*to)->prev = NULL;
		(*to)->next = NULL;
		return (1);
	}
	(*to)->prev = node_to_add;
	node_to_add->next = (*to);
	node_to_add->prev = NULL;
	(*to) = node_to_add;
	return (1);
}

int	reverse_rotate(t_node **head)
{
	t_node	*new_head;

	if (!head || !(*head) || listlen(*head) < 2)
		return (0);
	new_head = get_to_last_node(*head);
	new_head->prev->next = NULL;
	new_head->prev = NULL;
	new_head->next = (*head);
	(*head)->prev = new_head;
	(*head) = new_head;
	return (1);
}

int	rotate(t_node **head)
{
	t_node	*current;
	t_node	*new_head;

	if (!(*head) || listlen(*head) < 2)
		return (0);
	(*head)->next->prev = NULL;
	new_head = (*head)->next;
	current = get_to_last_node(*head);
	current->next = (*head);
	(*head)->prev = current;
	(*head)->next = NULL;
	(*head) = new_head;
	return (1);
}
