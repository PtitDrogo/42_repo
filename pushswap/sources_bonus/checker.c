/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:09:07 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/05 14:40:04 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int		execute_instructions(int valid_input, t_node **stack_a, t_node **stack_b);
static int		verify_input(char *input, char **valid);
static int		end_checking(t_node *stack_a, t_node *stack_b);
static int		free_all_KO_KO(t_node *stack_a, t_node *stack_b, char *toprint);

int main(int argc, char *argv[])
{
    t_node		*stack_a;
	t_node		*stack_b;
	int			median;
	char		*input;
	int			valid_input;

	static char *valid[] = {"sa\n", "sb\n", "ss\n", "ra\n", "rb\n", "rr\n", 
								"rra\n", "rrb\n", "rrr\n", "pa\n", "pb\n", NULL};
	stack_a = NULL;
	stack_b = NULL;
	if (arg_parsing(argc, argv, &median, &stack_a) == 0)
		free_all_and_error_exit(stack_a, stack_b);
	input = get_next_line(0);
	while (input)
	{
		valid_input = verify_input(input, valid);
		if (valid_input == -1)
			free_input_and_error_exit(stack_a, stack_b, input);
		execute_instructions(valid_input, &stack_a, &stack_b);
		free(input);
		input = get_next_line(0);
	}
	if (end_checking(stack_a, stack_b) == 0)
		free_all_KO_KO(stack_a, stack_b, "KO\n");
    free_all_KO_KO(stack_a, stack_b, "OK\n");
}

static int	execute_instructions(int valid_input, t_node **stack_a, t_node **stack_b)
{
	if (valid_input == 1)
		swap(stack_a);
	if (valid_input == 2)
		swap(stack_b);
	if (valid_input == 3)
		ss(stack_a, stack_b);
	if (valid_input == 4)
		rotate(stack_a);
	if (valid_input == 5)
		rotate(stack_b);
	if (valid_input == 6)
		rr(stack_a, stack_b);
	if (valid_input == 7)
		reverse_rotate(stack_a);
	if (valid_input == 8)
		reverse_rotate(stack_b);
	if (valid_input == 9)
		rrr(stack_a, stack_b);
	if (valid_input == 10)
		push(stack_b, stack_a);
	if (valid_input == 11)
		push(stack_a, stack_b);
	return (0);
}

static int	verify_input(char *input, char **valid)
{
	
	int	i;
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
				return (i + 1); //yes success we love it woohoo
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

static int	free_all_KO_KO(t_node *stack_a, t_node *stack_b, char *toprint)
{
	deallocate(stack_a);
	deallocate(stack_b);
	if (write(1, toprint, ft_strlen(toprint)) == -1)
		error_message_exit();
	exit(EXIT_SUCCESS);
	
}
