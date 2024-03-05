/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:09:07 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/05 15:24:47 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int		exec(int valid_input, t_node **stack_a, t_node **stack_b);
static int		verify_input(char *input, char **valid);
static int		end_checking(t_node *stack_a, t_node *stack_b);
static int		free_all_ok_ko(t_node *stack_a, t_node *stack_b, char *toprint);

int	main(int argc, char *argv[])
{
	t_node		*stack_a;
	t_node		*stack_b;
	char		*input;
	int			valid_input;
	static char	*valid[] = {"sa\n", "sb\n", "ss\n", "ra\n", "rb\n", "rr\n",
		"rra\n", "rrb\n", "rrr\n", "pa\n", "pb\n", NULL};

	stack_a = NULL;
	stack_b = NULL;
	if (arg_parsing(argc, argv, &stack_a) == 0)
		free_all_and_error_exit(stack_a, stack_b);
	input = get_next_line(0);
	while (input)
	{
		valid_input = verify_input(input, valid);
		if (valid_input == -1)
			free_input_and_error_exit(stack_a, stack_b, input);
		exec(valid_input, &stack_a, &stack_b);
		free(input);
		input = get_next_line(0);
	}
	if (end_checking(stack_a, stack_b) == 0)
		free_all_ok_ko(stack_a, stack_b, "KO\n");
	free_all_ok_ko(stack_a, stack_b, "OK\n");
}

static int	exec(int valid_input, t_node **stack_a, t_node **stack_b)
{
	if (valid_input == SA)
		swap(stack_a);
	if (valid_input == SB)
		swap(stack_b);
	if (valid_input == SS)
		ss(stack_a, stack_b);
	if (valid_input == RA)
		rotate(stack_a);
	if (valid_input == RB)
		rotate(stack_b);
	if (valid_input == RR)
		rr(stack_a, stack_b);
	if (valid_input == RRA)
		reverse_rotate(stack_a);
	if (valid_input == RRB)
		reverse_rotate(stack_b);
	if (valid_input == RRR)
		rrr(stack_a, stack_b);
	if (valid_input == PA)
		push(stack_b, stack_a);
	if (valid_input == PB)
		push(stack_a, stack_b);
	return (0);
}

static int	verify_input(char *input, char **valid)
{
	int		i;
	size_t	input_len;

	i = 0;
	if (!input)
		return (-1);
	while (valid[i])
	{
		input_len = ft_strlen(input);
		if (input_len == ft_strlen(valid[i]))
		{
			if (ft_strncmp(input, valid[i], input_len) == 0)
				return (i + 1);
		}
		i++;
	}
	return (-1);
}

static int	end_checking(t_node *stack_a, t_node *stack_b)
{
	if (stack_b != NULL)
		return (0);
	if (is_sorted(stack_a) == 0)
		return (0);
	else
		return (1);
}

static int	free_all_ok_ko(t_node *stack_a, t_node *stack_b, char *toprint)
{
	deallocate(stack_a);
	deallocate(stack_b);
	if (write(1, toprint, ft_strlen(toprint)) == -1)
		error_message_exit();
	exit(EXIT_SUCCESS);
}
