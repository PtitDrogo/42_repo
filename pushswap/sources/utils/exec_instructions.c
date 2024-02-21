/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:30:00 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/20 19:52:18 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	prepare_push_protocol(t_node *from, t_node *to, t_node **fromroot, t_node **to_root)
{
	printf("hi im in exec protocol\n");
    printf("from->instruction = %i  to->instruction = %i\n", from->instruction, to->instruction);
    printf("from->num_of_instructions = %i  to->num_of_instructions = %i\n", from->num_of_instructions, to->num_of_instructions);
    if (from->instruction == to->instruction)
		execute_same_instructions(from, to, fromroot, to_root);
	if (from->num_of_instructions || to->num_of_instructions)
		execute_different_instructions(from, to, fromroot, to_root);
	return ;
}
void	execute_same_instructions(t_node *from, t_node *to, t_node **fromroot, t_node **to_root)
{
	while (from->num_of_instructions && to->num_of_instructions)
	{
		if (from->instruction == ROTATE && to->instruction == ROTATE)		
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
		(to->num_of_instructions)--;
		printf("on est la est ce que ca decremente ce fdp %i and %i\n", from->num_of_instructions, to->num_of_instructions);
	}
	return ;
}
void	execute_different_instructions(t_node *from, t_node *to, t_node **fromroot, t_node **to_root)
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
	while (to->num_of_instructions > 0)
	{
		exec_rotate_or_rev_rotate(to->instruction, to_root);
		if (to->instruction == ROTATE)
			printf("rb\n"); //TEMP
		else if (to->instruction == REVERSE_ROTATE)
			printf("rrb\n"); //TEMP
		(to->num_of_instructions)--;
	}
}
void	exec_rotate_or_rev_rotate(int version, t_node **root)
{
	if (version == ROTATE)
		rotate(root); //writing the version doesnt change what happens, it just will print the wrong instruction
	else if (version == REVERSE_ROTATE)
		reverse_rotate(root); //honestly the print msg logic shouldnt be in the instruction maybe
	return ;
}