/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptitdrogo <ptitdrogo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:50:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/25 03:48:27 by ptitdrogo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
t_node  *find_target_node_bigger(const t_node *targetless_node, const t_node *root_target_stack);


void	push_back_to_stack_a(t_node **fromroot, t_node **to_root)
{
	t_node	*node_to_push;
	t_node	*target;
	
	while((*fromroot))
	{
		node_to_push = *fromroot;
		// printf("node to push number is %i and the first number of stack a is %i\n", node_to_push->number, (*to_root)->number);
		target = find_target_node_bigger(node_to_push, *to_root);
		// printf("target is %i\n", target->number);
		if (target && (rotate_and_count(target) < rev_rotate_and_count(target)))
			while (target->prev)
				safe_exec_one_stack(rotate, to_root, fromroot, "ra\n");
		else if (target)
			while (target->prev)
				safe_exec_one_stack(reverse_rotate, to_root, fromroot, "rra\n");
		push(fromroot, to_root);
		printf("pa\n");
	}
	
}


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
		// printf("current cheapest instruction value is %i\n", cheapest_instructions_value);
		current_value = find_instruc_number_and_direction(current, current->target_node);
		if (cheapest_instructions_value > current_value)
		{	
			cheapest_instructions_value = current_value;
			cheapest_node = current;
		}
		current = current->next;
	}
	// printf("return value of  %i\n", cheapest_instructions_value);
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
	// printf("\nHI from n = %i, target_node n = %i, full rotate = %i, full rev rotate = %i, mixed n = %i\n", from->number, target_node->number, full_rotate, full_reverse_rotate, mixed);
	
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
	{	
		set_instructions_numbers(from, target_node);
		return (mixed);
	}
}
void	set_instructions_numbers(t_node *a_node, t_node *b_node)
{
	if (a_node->instruction == ROTATE)
		a_node->num_of_instructions = rotate_and_count(a_node);
	else if (a_node->instruction == REVERSE_ROTATE)
		a_node->num_of_instructions = rev_rotate_and_count(a_node);
	if (b_node->instruction == ROTATE)
		b_node->num_of_instructions = rotate_and_count(b_node);
	else if (b_node->instruction == REVERSE_ROTATE)
		b_node->num_of_instructions = rev_rotate_and_count(b_node);
	// printf("\nIN set instructions numbers : a = %i, b = %i\n", a_node->num_of_instructions, b_node->num_of_instructions);
	return ;
}

int	calculate_mixed_instructions(t_node *from, t_node *target_node)
{
	int	mix_a;
	int	mix_b;

	mix_a = rotate_and_count(from) + rev_rotate_and_count(target_node);
	mix_b = rev_rotate_and_count(from) + rotate_and_count(target_node);
	// printf("in mixec calc, mix_a = %i and mix_b = %i\n", mix_a, mix_b);
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

int rev_rotate_and_count(const t_node *node)
{
	int i;
	t_node	*current;

	i = 0;
	current = (t_node *) node;
	if (node->prev == NULL)
		return (0); // doesnt work for mixed i think
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
int rotate_and_count(const t_node *node)
{
	int i;
	t_node	*current;
	
	i = 0;
	current = (t_node *) node;
	// if (node->prev == NULL)
	// 	return (0); //gonna need two different functions/condition heres.
	while (current->prev)
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
		// printf("from with number %i has target node = to %i\n", from->number, from->target_node->number);
		from = from->next;
	}
	return ;
}

t_node	*find_biggest_number_node(const t_node *root_target_stack)
{	
	t_node	*current;
	t_node	*target;
	int		biggest_n;
	
	target = NULL;
	biggest_n = INT_MIN;
	current = (t_node *) root_target_stack;
	while (current)
	{
		if (current->number >= biggest_n)
		{	
			target = current;
			biggest_n = current->number;
		}
		current = current->next;
	}
	return (target);
}
t_node	*find_smaller_number_node(const t_node *root_target_stack)
{	
	t_node	*current;
	t_node	*target;
	int		smaller_n;
	
	target = NULL;
	smaller_n = INT_MAX;
	current = (t_node *) root_target_stack;
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

t_node  *find_target_node(const t_node *targetless_node, const t_node *root_target_stack)
{
	int			closest_number;
	t_node		*current;
	t_node		*target;

	target = NULL;
	closest_number = INT_MIN;
	current = (t_node *) root_target_stack;
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
	if (target == NULL)
		target = find_biggest_number_node(root_target_stack);
	return (target);
}

t_node  *find_target_node_bigger(const t_node *targetless_node, const t_node *root_target_stack)
{
	int			closest_number;
	t_node		*current;
	t_node		*target;

	target = NULL;
	closest_number = INT_MAX;
	current = (t_node *) root_target_stack;
	while (current)
	{
		// printf("current num is %i and targetless_node->number is %i and closest number is %i\n", current->number, targetless_node->number, closest_number);
		if (current->number > targetless_node->number && current->number < closest_number)
		{	
			closest_number = current->number;
			target = current;
		}
		current = current->next;
	}
	if (target == NULL)
		target = find_smaller_number_node(root_target_stack);
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
	if (a > b && b < c && c < a)
	{	
		rotate(roota);
		printf("ra\n");
	}
	else if (a < b && b > c && c < a)
	{	
		reverse_rotate(roota);
		printf("rra\n");
	}
	else
	{
		swap(roota);
		printf("sa\n");
		if (a < b && b > c && c > a)
		{	
			printf("ra\n");
			rotate(roota);
		}
		else if (a > b && b > c && c < a)
		{	
			printf("rra\n");
			reverse_rotate(roota);
		}
	}
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

