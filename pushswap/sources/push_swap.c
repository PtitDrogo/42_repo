/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:46 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/28 20:46:54 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	final_sort(t_node **stack_a, t_node **stack_b);
static void	flush_stacks(t_node *roota, t_node *rootb);
static void	early_exit(int argc, char *argv[], t_node *stacka, t_node *stackb);
static int	push_to_median(t_node **from, t_node **to, int median);

int	main(int argc, char *argv[])
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_node		*cheapest_node;
	int			median;

	stack_a = NULL;
	stack_b = NULL;
	if (arg_parsing(argc, argv, &median, &stack_a) == 0)
		free_all_and_error_exit(stack_a, stack_b);
	early_exit(argc, argv, stack_a, stack_b);
	push_to_median(&stack_a, &stack_b, median);
	sort_3(&stack_a, &stack_b);
	while (stack_b)
	{
		find_all_target_nodes(stack_b, stack_a);
		cheapest_node = find_cheapest_node(stack_b);
		prepare_push_protocol(cheapest_node, &stack_b, &stack_a);
		exec_two(push, &stack_b, &stack_a, "pa\n");
		flush_stacks(stack_a, stack_b);
	}
	final_sort(&stack_a, &stack_b);
	free_all_and_exit(stack_a, stack_b);
}

static void	flush_stacks(t_node *roota, t_node *rootb)
{
	t_node	*current;

	current = roota;
	while (current)
	{
		init_node(current);
		current = current->next;
	}
	current = rootb;
	while (current)
	{
		init_node(current);
		current = current->next;
	}
	return ;
}

static void	early_exit(int argc, char *argv[], t_node *stack_a, t_node *stack_b)
{
	if (is_sorted(stack_a))
		free_all_and_exit(stack_a, stack_b);
	if (listlen(stack_a) == 2)
	{
		exec_one(swap, &stack_a, &stack_b, "sa\n");
		free_all_and_exit(stack_a, stack_b);
	}
}

static int	push_to_median(t_node **from, t_node **to, int median)
{
	int		number;
	int		list_len;

	list_len = listlen(*from);
	while ((*from) && list_len > 3)
	{
		number = (*from)->number;
		exec_two(push, from, to, "pb\n");
		if (number < median)
			exec_one(rotate, to, from, "rb\n");
		list_len--;
	}
	return (0);
}

static void	final_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*first;

	first = find_smaller_number_node(*stack_a);
	if (revr_count(first) > r_count(first))
	{
		while (first != (*stack_a))
			exec_one(rotate, stack_a, stack_b, "ra\n");
	}
	else
	{
		while (first != (*stack_a))
			exec_one(reverse_rotate, stack_a, stack_b, "rra\n");
	}
}
