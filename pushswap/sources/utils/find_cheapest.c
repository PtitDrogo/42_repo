/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:12:10 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/28 20:17:32 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_vector(t_node *from, t_node *target_node);
static int	mixed_count(t_node *from, t_node *target_node);
static void	set_instructions_numbers(t_node *a_node, t_node *b_node);

t_node	*find_cheapest_node(const t_node *from)
{
	t_node	*current;
	t_node	*cheapest_node;
	int		cheapest_instructions_value;
	int		current_value;

	cheapest_node = NULL;
	cheapest_instructions_value = INT_MAX;
	current = (t_node *) from;
	while (current)
	{
		current_value = find_vector(current, current->target_node);
		if (cheapest_instructions_value > current_value)
		{
			cheapest_instructions_value = current_value;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}

static int	find_vector(t_node *from, t_node *target_node)
{
	int	full_rotate;
	int	full_reverse_rotate;
	int	mixed;

	full_rotate = best_of(r_count(from), r_count(target_node));
	full_reverse_rotate = best_of(revr_count(from), revr_count(target_node));
	mixed = mixed_count(from, target_node);
	if (full_rotate < full_reverse_rotate && full_rotate < mixed)
	{
		from->instruction = ROTATE;
		target_node->instruction = ROTATE;
		set_instructions_numbers(from, target_node);
		return (full_rotate);
	}
	else if (full_reverse_rotate < full_rotate && full_reverse_rotate < mixed)
	{
		from->instruction = REVERSE_ROTATE;
		target_node->instruction = REVERSE_ROTATE;
		set_instructions_numbers(from, target_node);
		return (full_reverse_rotate);
	}
	else
		return (set_instructions_numbers(from, target_node), mixed);
}

static int	mixed_count(t_node *from, t_node *target_node)
{
	int	mix_a;
	int	mix_b;

	mix_a = r_count(from) + revr_count(target_node);
	mix_b = revr_count(from) + r_count(target_node);
	if (mix_a < mix_b)
	{
		from->instruction = ROTATE;
		target_node->instruction = REVERSE_ROTATE;
		return (mix_a);
	}
	else
	{
		from->instruction = REVERSE_ROTATE;
		target_node->instruction = ROTATE;
		return (mix_b);
	}
}

static void	set_instructions_numbers(t_node *a_node, t_node *b_node)
{
	if (a_node->instruction == ROTATE)
		a_node->num_of_instructions = r_count(a_node);
	else if (a_node->instruction == REVERSE_ROTATE)
		a_node->num_of_instructions = revr_count(a_node);
	if (b_node->instruction == ROTATE)
		b_node->num_of_instructions = r_count(b_node);
	else if (b_node->instruction == REVERSE_ROTATE)
		b_node->num_of_instructions = revr_count(b_node);
	return ;
}
