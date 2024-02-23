/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:30:00 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/22 15:59:52 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	smart_print(int instruction, int stack);

void	prepare_push_protocol(t_node *from, t_node **fromroot, t_node **to_root, int stack_of_from)
{
	// printf("hi im in exec protocol\n");
    // printf("from->instruction = %i  to->instruction = %i\n", from->instruction, from->target_node->instruction);
    // printf("from->num_of_instructions = %i  from->target_node->num_of_instructions = %i\n", from->num_of_instructions, from->target_node->num_of_instructions);
    if (from->instruction == from->target_node->instruction)
		execute_same_instructions(from, fromroot, to_root);
	if (from->num_of_instructions || from->target_node->num_of_instructions)
		execute_different_instructions(from, fromroot, to_root, stack_of_from);
	return ;
}
void	execute_same_instructions(t_node *from, t_node **fromroot, t_node **to_root)
{
	
	while (from->num_of_instructions && from->target_node->num_of_instructions)
	{
		if (from->instruction == ROTATE && from->target_node->instruction == ROTATE)		
		{
			rr(fromroot, to_root);
			printf("rr\n"); //TEMP
		}
		else
		{
			rrr(fromroot, to_root);
			printf("rrr\n"); // temp
		}
		(from->num_of_instructions)--;
		(from->target_node->num_of_instructions)--;
		// printf("on est la est ce que ca decremente ce fdp %i and %i\n", from->num_of_instructions, from->target_node->num_of_instructions);
	}
	return ;
}
void	execute_different_instructions(t_node *from, t_node **fromroot, t_node **to_root, int stack_of_from)
{
	while (from->num_of_instructions > 0)
	{
		exec_rotate_or_rev_rotate(from->instruction, fromroot);
		smart_print(from->instruction, stack_of_from);
		(from->num_of_instructions)--;
	}
	if (stack_of_from == A)
		stack_of_from = B;
	else
		stack_of_from = A;
	while (from->target_node->num_of_instructions > 0)
	{
		exec_rotate_or_rev_rotate(from->target_node->instruction, to_root);
		smart_print(from->instruction, stack_of_from);
		(from->target_node->num_of_instructions)--;
	}
}
void	exec_rotate_or_rev_rotate(int version, t_node **root)
{
	if (version == ROTATE)
		rotate(root);
	else if (version == REVERSE_ROTATE)
		reverse_rotate(root);
	return ;
}

void	smart_print(int instruction, int stack)
{
	if (stack == A)
	{
		if (instruction == ROTATE)
			printf("ra\n"); //TEMP
		else if (instruction == REVERSE_ROTATE)
			printf("rra\n"); //TEMP
	}
	else if (stack == B)
	{
		if (instruction == ROTATE)
			printf("rb\n"); //TEMP
		else if (instruction == REVERSE_ROTATE)
			printf("rrb\n"); //TEMP
	}
	return ;
}