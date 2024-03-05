/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_target.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:50:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/05 14:55:55 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_node	*find_target(const t_node *targetless, const t_node *to);

void	find_all_target_nodes(t_node *from, t_node *to)
{
	while (from)
	{
		from->target_node = find_target(from, to);
		from = from->next;
	}
	return ;
}

static t_node	*find_target(const t_node *targetless, const t_node *to)
{
	int			closest_number;
	t_node		*curr;
	t_node		*target;

	target = NULL;
	closest_number = INT_MAX;
	curr = (t_node *) to;
	while (curr)
	{
		if (curr->number > targetless->number && curr->number <= closest_number)
		{
			closest_number = curr->number;
			target = curr;
		}
		curr = curr->next;
	}
	if (target == NULL)
		target = find_smaller_number_node(to);
	return (target);
}

t_node	*find_smaller_number_node(const t_node *to)
{
	t_node	*current;
	t_node	*target;
	int		smaller_n;

	target = NULL;
	smaller_n = INT_MAX;
	current = (t_node *) to;
	while (current)
	{
		if (current->number <= smaller_n)
		{
			target = current;
			smaller_n = current->number;
		}
		current = current->next;
	}
	return (target);
}
