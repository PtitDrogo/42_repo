/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:30:00 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/28 20:15:21 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	same_instruct(t_node *from, t_node **fromroot, t_node **to_root);
static void	diff_instruct(t_node *from, t_node **fromroot, t_node **to_root);

void	prepare_push_protocol(t_node *from, t_node **fromroot, t_node **to_root)
{
	if (from->instruction == from->target_node->instruction)
		same_instruct(from, fromroot, to_root);
	if (from->num_of_instructions || from->target_node->num_of_instructions)
		diff_instruct(from, fromroot, to_root);
	return ;
}

static void	same_instruct(t_node *from, t_node **fromroot, t_node **to_root)
{
	t_node	*target;

	target = from->target_node;
	while (from->num_of_instructions && target->num_of_instructions)
	{
		if (from->instruction == ROTATE && target->instruction == ROTATE)
			exec_two(rr, fromroot, to_root, "rr\n");
		else
			exec_two(rrr, fromroot, to_root, "rrr\n");
		(from->num_of_instructions)--;
		(target->num_of_instructions)--;
	}
	return ;
}

static void	diff_instruct(t_node *from, t_node **fromroot, t_node **to_root)
{
	while (from->num_of_instructions > 0)
	{
		if (from->instruction == ROTATE)
			exec_one(rotate, fromroot, to_root, "rb\n");
		else if (from->instruction == REVERSE_ROTATE)
			exec_one(reverse_rotate, fromroot, to_root, "rrb\n");
		(from->num_of_instructions)--;
	}
	while (from->target_node->num_of_instructions > 0)
	{
		if (from->target_node->instruction == ROTATE)
			exec_one(rotate, to_root, fromroot, "ra\n");
		else if (from->target_node->instruction == REVERSE_ROTATE)
			exec_one(reverse_rotate, to_root, fromroot, "rra\n");
		(from->target_node->num_of_instructions)--;
	}
}
