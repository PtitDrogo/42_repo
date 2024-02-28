/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:32:44 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/28 20:16:46 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	best_of(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	revr_count(const t_node *node)
{
	int		i;
	t_node	*current;

	i = 0;
	current = (t_node *) node;
	if (node->prev == NULL)
		return (0);
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	r_count(const t_node *node)
{
	int		i;
	t_node	*current;

	i = 0;
	current = (t_node *) node;
	while (current->prev)
	{
		i++;
		current = current->prev;
	}
	return (i);
}

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}
