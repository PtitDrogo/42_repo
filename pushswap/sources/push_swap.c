/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:46 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/28 00:11:01 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		insert_end(t_node **root, int value);
void	flush_stacks(t_node *roota, t_node *rootb);
void	init_node(t_node *new_node);

int     push_to_median(t_node **from, t_node **to, int median)
{
    int     number;
    int     list_len;
	
    list_len = listlen(*from);
    while ((*from) && list_len > 3)
    {
        number = (*from)->number;
        exec_two(push, from, to, "pb\n");
        if (number < median) 
			exec_one(rotate, to, from, "rb\n");
        list_len--;
	}
    return 0;
}

int main(int argc, char *argv[])
{
	t_node		*roota;
	t_node		*rootb;
	t_node 		*cheapest_node;
	int			median;
	
	roota = NULL;
	rootb = NULL;
	if (arg_parsing(argc, argv, &median, &roota) == 0)
		free_all_and_error_exit(roota, rootb);
	if (is_sorted(roota))
		free_all_and_exit(roota, rootb);
	if (listlen(roota) == 2)
	{	
		exec_one(swap, &roota, &rootb, "sa\n");
		free_all_and_exit(roota, rootb);
	}
	push_to_median(&roota, &rootb, median);
	sort_3(&roota, &rootb);
	while ((rootb))
	{	
		find_all_target_nodes(rootb, roota);
		cheapest_node = find_cheapest_node(rootb);
		prepare_push_protocol(cheapest_node, &rootb, &roota);
		exec_two(push, &rootb, &roota, "pa\n");
		flush_stacks(roota, rootb);
	}
	///FUNCTION
	t_node *first = find_smaller_number_node(roota);
	if (rev_rotate_and_count(roota) < rotate_and_count(roota))
	{
		while (first != roota)
			exec_one(rotate, &roota, &rootb, "ra\n");
	}
	else
		while (first != roota)
			exec_one(reverse_rotate, &roota, &rootb, "rra\n");
	//FUNCTION

	free_all_and_exit(roota, rootb);
}
void	flush_stacks(t_node *roota, t_node *rootb)
{
	t_node *current;

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

void	free_array_from_index(void **array, int j)
{
	while (j > 0)
	{
		j--;
		if (array[j])
			free(array[j]);
	}
	free(array);
	return ;
}







