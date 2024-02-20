/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:50:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/20 19:31:22 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



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
		printf("current cheapest instruction value is %i\n", cheapest_instructions_value);
		current_value = find_instruc_number_and_direction(current, current->target_node);
		if (cheapest_instructions_value > current_value)
		{	
			cheapest_instructions_value = current_value;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}

int	find_instruc_number_and_direction(t_node *from, t_node *target_node)
{
	int full_rotate;
	int	full_reverse_rotate;
	int mixed;
	
	full_rotate = calculate_with_synergies(rotate_and_count(from), rotate_and_count(target_node));
	full_reverse_rotate = calculate_with_synergies(rev_rotate_and_count(from), rev_rotate_and_count(target_node));
	mixed = calculate_mixed_instructions(from, target_node);
	printf("from n = %i, target_node n = %i, full rotate = %i, full rev rotate = %i, mixed n = %i\n", from->number, target_node->number, full_rotate, full_reverse_rotate, mixed);
	
	if (full_rotate < full_reverse_rotate && full_rotate < mixed)
	{	
		from->instruction = ROTATE;
		target_node->instruction = ROTATE;
		return (full_rotate);
	}
	else if (full_reverse_rotate < full_rotate && full_reverse_rotate < mixed)
	{	
		from->instruction = REVERSE_ROTATE;
		target_node->instruction = REVERSE_ROTATE;
		return (full_reverse_rotate);
	}		
	else
		return (mixed);
}

int	calculate_mixed_instructions(t_node *from, t_node *target_node)
{
	int	mix_a;
	int	mix_b;

	mix_a = rotate_and_count(from) + rev_rotate_and_count(target_node);
	mix_b = rev_rotate_and_count(from) + rotate_and_count(target_node);
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

int	calculate_with_synergies(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}


int rotate_and_count(const t_node *node)
{
	int i;
	t_node	*current;

	i = 0;
	current = (t_node *) node;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (i);
}
int rev_rotate_and_count(const t_node *node)
{
	int i;
	t_node	*current;
	
	i = 0;
	current = (t_node *) node;
	while (current)
	{
		i++;
		current = current->prev;
	}
	return (i);
}



void	find_all_target_nodes(t_node *from, t_node *to)
{
	while (from)
	{
		from->target_node = find_target_node(from, to);
		printf("from with number %i has target node = to %i\n", from->number, from->target_node->number);
		from = from->next;
	}
	return ;
}

t_node	*find_smallest_number_node(const t_node *root_target_stack)
{
	t_node	*current;
	t_node	*target;
	int		smallest_n;
	
	target = NULL;
	smallest_n = INT_MAX;
	current = (t_node *) root_target_stack;
	while (current)
	{
		if (current->number <= smallest_n)
		{	
			target = current;
			smallest_n = current->number;
		}
		current = current->next;
	}
	return (target);
}


t_node  *find_target_node(const t_node *targetless_node, const t_node *root_target_stack)
{
	//we will use the same function twice with one small difference, but for
	//now lets just code this for the first case;
	int			closest_number;
	t_node		*current;
	t_node		*target;

	target = NULL; //should be useless after additionnal checking
	closest_number = INT_MIN;
	current = (t_node *) root_target_stack;
	// printf("current start at %p\n", current);
	while (current)
	{
		// printf("current num is %i and targetless_node->number is %i and closest number is %i\n", current->number, targetless_node->number, closest_number);
		if (current->number < targetless_node->number && current->number > closest_number)
		{	
			closest_number = current->number;
			target = current;
		}
		current = current->next;
	}
	if (closest_number == INT_MIN)
		target = find_smallest_number_node(root_target_stack);
	printf("target is %p", target);
	return (target);
}
void    sort_3(t_node **roota)
{
	t_node  *current;
	int     a;
	int     b;
	int     c;

	if (is_sorted(*roota))
		return ;
	current = (*roota);
	a = (current->number);
	b = (current->next->number);
	c = (current->next->next->number);
	if (a < b && b > c && c < a)
		rotate(roota);
	else if (a > b && b < c && c < a)
		reverse_rotate(roota);
	else if (a < b && b > c && c > a)
		swap(*roota);
	else if (a > b)
	{
		swap(*roota);
		if (b > c)
			reverse_rotate(roota);
		else if (b < c)
			rotate(roota);
	}
}

int is_sorted(const t_node *roota)
{
	int i;
	t_node  *current;

	current = (t_node *)roota;
	i = INT_MIN;
	
	while (current)
	{
		// printf("comparing if %i is smaller than %i\n", current->number, i);
		if (current->number < i)
		{    
			// printf("about to return not sorted");
			return (0);
		}
		i = current->number;
		current = current->next; 
	}
	return (1);
}

