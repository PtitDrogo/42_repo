/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:50:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/16 20:17:37 by tfreydie         ###   ########.fr       */
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
		current_value = find_instructions_number(current, current->target_node);
		if (cheapest_instructions_value > current_value)
		{	
			cheapest_instructions_value = current_value;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}

int	find_instructions_number(const t_node *from, const t_node *target_node)
{
	int full_rotate;
	int	full_reverse_rotate;
	int	mixed;
	
	full_rotate = calculate_with_synergies(instruct_rotate(from), instruct_rotate(target_node));
	full_reverse_rotate = calculate_with_synergies(instruct_rev_rotate(from), instruct_rev_rotate(target_node));
	mixed = calculate_mixed_instructions(from, target_node);
	printf("from n = %i, target_node n = %i, full rotate = %i, full rev rotate = %i, mixed n = %i\n", from->number, target_node->number, full_rotate, full_reverse_rotate, mixed);
	
	if (full_rotate < full_reverse_rotate && full_reverse_rotate < mixed)
		return (full_rotate);
	else if (full_reverse_rotate < full_rotate && full_reverse_rotate < mixed)
		return (full_reverse_rotate);
	else
		return (mixed);
}

int	calculate_mixed_instructions(const t_node *from, const t_node *target_node)
{
	int	mix_a;
	int	mix_b;

	mix_a = instruct_rotate(from) + instruct_rev_rotate(target_node);
	mix_b = instruct_rev_rotate(from) + instruct_rotate(target_node);
	if (mix_a < mix_b)
		return (mix_a);
	else
		return (mix_b);
}

// int	calculate_with_synergies(int a, int b)
// {
// 	int result;
// 	int synergies;

// 	printf("a = %i and b = %i\n",a ,b);
// 	synergies = b - a;
// 	synergies = synergies * ((synergies > 0) - (synergies < 0));
// 	result = a + synergies;
// 	return (result);
// }
int	calculate_with_synergies(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}


int instruct_rotate(const t_node *node)
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
int instruct_rev_rotate(const t_node *node)
{
	int i;
	t_node	*current;
	
	i = 0;
	current = (t_node *) node;
	while (current) //i think this is correct instead of current->prev because it needs one more to go on top;
	{
		i++;
		current = current->prev;
	}
	return (i);
}

// int instructions_to_top_reverse_rotate(t_node *node)
// {
// 	int i;
	
// 	while (node->next)
// 	{
// 		i++;
// 		node = node->next;
// 	}
// }

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
		rotate(roota, "ra");
	else if (a > b && b < c && c < a)
		reverse_rotate(roota, "rra");
	else if (a < b && b > c && c > a)
		swap(*roota, "sa");
	else if (a > b)
	{
		swap(*roota, "sa");
		if (b > c)
			reverse_rotate(roota, "rra");
		else if (b < c)
			rotate(roota, "ra");
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
// t_node  *meme_findtarget_node(const t_node *targetless_node, const t_node *root_target_stack)
// {
// 	long long	node_number;
// 	long long	difference;
// 	long long	tmp_diff;
// 	t_node		*cursor;
// 	t_node		*target;
	
// 	difference = LONG_MAX;
// 	node_number = targetless_node->number;
// 	cursor = (t_node *)root_target_stack;
// 	while (cursor)
// 	{
// 		tmp_diff = (node_number - cursor->number);
// 		tmp_diff = tmp_diff * ((tmp_diff > 0) - (tmp_diff < 0));
// 		if (tmp_diff < difference)
// 		{    
// 			difference = tmp_diff;
// 			target = cursor; //maybe we will change the struct directly here well see
// 		}
// 		cursor = cursor->next;
// 	}
// 	return (target);
// }
