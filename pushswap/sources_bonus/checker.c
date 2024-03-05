/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:09:07 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/05 13:26:16 by tfreydie         ###   ########.fr       */
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
    while (input)
	{
		input = get_next_line(0);
		valid_input = verify_input(input, valid);
		if (valid_input == -1);
			free_all_and_error_exit(stack_a, stack_b);
		if (execute_instructions(valid_input, &stack_a, &stack_b) == 0)
			free_all_and_error_exit(stack_a, stack_b);
		free(input);
	}
	if (end_checking(stack_a, stack_b) == 0)
		free_all_KO_KO(stack_a, stack_b, "KO\n");
    free_all_KO_KO(stack_a, stack_b, "OK\n");
}

static int	execute_instructions(int valid_input, t_node **stack_a, t_node **stack_b)
{
	//dans les exec rajouter le fait de se casser si un fail;
	if (valid_input == 1)
		return(exec_one(swap, stack_a, stack_b, "sa\n"));
	if (valid_input == 2)
		return(exec_one(swap, stack_b, stack_a, "sb\n"));
	if (valid_input == 3)
		return(exec_two(ss, stack_a, stack_b, "ss\n"));
	if (valid_input == 4)
		return(exec_one(rotate, stack_a, stack_b, "ra\n"));
	if (valid_input == 5)
		return(exec_one(rotate, stack_b, stack_a, "rb\n"));
	if (valid_input == 6)
		return(exec_two(rr, stack_a, stack_b, "rr\n"));
	if (valid_input == 7)
		return(exec_one(reverse_rotate, stack_a, stack_b, "rra\n"));
	if (valid_input == 8)
		return(exec_one(reverse_rotate, stack_b, stack_a, "rrb\n"));
	if (valid_input == 9)
		return(exec_one(reverse_rotate, stack_a, stack_b, "rrr\n"));
	if (valid_input == 10)
		return(exec_two(push, stack_b, stack_a, "pa\n"));
	if (valid_input == 11)
		return(exec_two(push, stack_a, stack_b, "pb\n"));
	return (0);
}

static int	verify_input(char *input, char **valid)
{
	
	int	i;
	size_t	input_len;
	
	i = 0;
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
	if (write(1, toprint, ft_strlen(toprint) == -1))
		error_message_exit();
	exit(EXIT_SUCCESS);
	
}
