/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptitdrogo <ptitdrogo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:30:00 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/25 02:53:50 by ptitdrogo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
			safe_exec_two_stack(rr, fromroot, to_root, "rr\n");
		else
			safe_exec_two_stack(rrr, fromroot, to_root, "rrr\n");
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
		if (from->instruction == ROTATE)
			safe_exec_one_stack(rotate, fromroot, to_root, "ra\n");
		else if (from->instruction == REVERSE_ROTATE)
			safe_exec_one_stack(reverse_rotate, fromroot, to_root, "rra\n");
		(from->num_of_instructions)--;
	}
	while (from->target_node->num_of_instructions > 0)
	{
		if (from->target_node->instruction == ROTATE)
			safe_exec_one_stack(rotate, to_root, fromroot, "rb\n");
		else if (from->target_node->instruction == REVERSE_ROTATE)
			safe_exec_one_stack(reverse_rotate, to_root, fromroot, "rrb\n");
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