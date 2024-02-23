/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:30:00 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/23 19:11:49 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	smart_print(int instruction, int stack);

void	prepare_push_protocol(t_node *from, t_node **fromroot, t_node **to_root)
{
	// printf("hi im in exec protocol\n");
    // printf("from->instruction = %i  to->instruction = %i\n", from->instruction, from->target_node->instruction);
    // printf("from->num_of_instructions = %i  from->target_node->num_of_instructions = %i\n", from->num_of_instructions, from->target_node->num_of_instructions);
    if (from->instruction == from->target_node->instruction)
		execute_same_instructions(from, fromroot, to_root);
	if (from->num_of_instructions || from->target_node->num_of_instructions)
		execute_different_instructions(from, fromroot, to_root);
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
void	execute_different_instructions(t_node *from, t_node **fromroot, t_node **to_root)
{
	while (from->num_of_instructions > 0)
	{
		exec_rotate_or_rev_rotate(from->instruction, fromroot);
		if (from->instruction == ROTATE)
			printf("ra\n"); //TEMP
		else if (from->instruction == REVERSE_ROTATE)
			printf("rra\n"); //TEMP
		(from->num_of_instructions)--;
	}
	while (from->target_node->num_of_instructions > 0)
	{
		exec_rotate_or_rev_rotate(from->target_node->instruction, to_root);
		if (from->target_node->instruction == ROTATE)
			printf("rb\n"); //TEMP
		else if (from->target_node->instruction == REVERSE_ROTATE)
			printf("rrb\n"); //TEMP
		// printf("from->instruction = %i\n", from->instruction);
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