/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 03:21:27 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/28 20:13:25 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*get_to_last_node(t_node *root)
{
	if (!root)
		return (NULL);
	while (root->next)
		root = root->next;
	return (root);
}

int	listlen(t_node *root)
{
	int	i;

	i = 0;
	while (root)
	{
		root = root->next;
		i++;
	}
	return (i);
}

int	is_sorted(const t_node *heada)
{
	int		i;
	t_node	*current;

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

void	sort_3(t_node **roota, t_node **rootb)
{
	t_node	*current;
	int		a;
	int		b;
	int		c;

	if (is_sorted(*roota))
		return ;
	current = (*roota);
	a = (current->number);
	b = (current->next->number);
	c = (current->next->next->number);
	if (a > b && b < c && c < a)
		exec_one(rotate, roota, rootb, "ra\n");
	else if (a < b && b > c && c < a)
		exec_one(reverse_rotate, roota, rootb, "rra\n");
	else
	{
		exec_one(swap, roota, rootb, "sa\n");
		if (a < b && b > c && c > a)
			exec_one(rotate, roota, rootb, "ra\n");
		else if (a > b && b > c && c < a)
			exec_one(reverse_rotate, roota, rootb, "rra\n");
	}
}
