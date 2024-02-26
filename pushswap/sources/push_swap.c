/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptitdrogo <ptitdrogo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:46 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/26 03:10:24 by ptitdrogo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		init_number_list(int argc, char *argv[], t_node **root);
int		insert_end(t_node **root, int value);
void	flush_stacks(t_node *roota, t_node *rootb);
void	init_node(t_node *new_node);


// void	*my_malloc(size_t size) 
// {
//     static int counter = 0;
//     counter++;
//     if (counter == 3) { // Simulate failure on every 5th call
//         return NULL;
//     }
//     return malloc(size);
// }
// # define malloc(size) my_malloc(size)

int     push_to_median(t_node **from, t_node **to, int median)
{
    int     number;
    int     list_len;
	
    list_len = listlen(*from);
    while ((*from) && list_len > 1) //&& list_len > 3 in theory, but it leaks for some reason
    {
        number = (*from)->number;
        safe_exec_two_stack(push, from, to, "pb\n");
        if (number < median) //somehow this is important test for the best
			safe_exec_one_stack(rotate, to, from, "rb\n");
        list_len--;
    }
    return 0;
}

void	print_list(t_node *root)
{
	printf("printing from head/sommet to tail\n");
	if (root != NULL)
	{
		while (root->next)
		{
			// sleep(1);
			printf("%i \n", root->number);
			// printf("instruction is %i (1 = Rot 2 = RevRot) \n", root->instruction);
			root = root->next;
		}
		printf("%i \n", root->number);
		// printf("instruction is %i (1 = Rot 2 = RevRot) \n", root->instruction);
	}
	// printf("printing from tail to head/sommet\n");
	// if (root != NULL)
	// {
	// 	while (root->prev)
	// 	{
	// 		// sleep(1);
	// 		printf("%i\n", root->number);
	// 		root = root->prev;
	// 	}
	// 	printf("%i\n", root->number);
	// }
	return ;
}

int main(int argc, char *argv[])
{
	t_node		*roota;
	t_node		*rootb;
	t_node *cheapest_node;
	int	*median = malloc(sizeof(int));

	roota = NULL;
	rootb = NULL;
	if (init_number_list(argc, argv, &roota) == 0)
		free_all_and_error_exit(roota, rootb);
	if (arg_parsing(argc, argv, median) == 0)
		free_all_and_error_exit(roota, rootb);
	if (is_sorted(roota))
	{	
		deallocate(roota);
		deallocate(rootb);
		return (0); //its this or above;
	}
	// safe_exec_two_stack(push, &roota, &rootb, "pb\n");
	// safe_exec_two_stack(push, &roota, &rootb, "pb\n");
	
	// while (listlen(roota) > 3)
	// {	
	// 	// printf("printing stack a\n");
	// 	// print_list(roota);
	// 	// printf("printing stack b\n");
	// 	// print_list(rootb);
	// 	// sleep(10);
	// 	find_all_target_nodes(roota, rootb);
	// 	cheapest_node = find_cheapest_node(roota);
	// 	// printf("my cheapest node with value %i has target node whose value is %i\n", cheapest_node->number, cheapest_node->target_node->number);
	// 	prepare_push_protocol(cheapest_node, &roota, &rootb);
	// 	push(&roota, &rootb);
	// 	printf("pb\n");
	// 	flush_stacks(roota, rootb);
	// }
	
	// // t_node *final_head = malloc(sizeof(t_node *));
	// t_node *final_head = find_smaller_number_node(roota);
	// // printf("smallest number = %i\n", final_head->number);
	// if (final_head && rotate_and_count(final_head) < rev_rotate_and_count(final_head))
	// 	while (final_head->prev)
	// 		safe_exec_one_stack(rotate, &roota, &rootb, "ra\n");
	// else
	// 	while (final_head->prev)
	// 		safe_exec_one_stack(reverse_rotate, &roota, &rootb, "rra\n");
	
	
	// //meme attempt;
	push_to_median(&roota, &rootb, *median);
	// sort_3(&roota);

	//////////////////MEDIAN ATTEMPT
	while ((rootb))
	{	
		// printf("printing stack a\n");
		// print_list(roota);
		// printf("printing stack b\n");
		// print_list(rootb);
		// sleep(10);
		find_all_target_nodes(rootb, roota);
		cheapest_node = find_cheapest_node(rootb);
		// printf("my cheapest node with value %i has target node whose value is %i\n", cheapest_node->number, cheapest_node->target_node->number);
		prepare_push_protocol(cheapest_node, &rootb, &roota);
		push(&rootb, &roota);
		printf("pa\n");
		flush_stacks(roota, rootb);
	}
	t_node *first = find_smaller_number_node(roota);
	if (rev_rotate_and_count(roota) < rotate_and_count(roota))
	{
		while (first != roota)
			safe_exec_one_stack(rotate, &roota, &rootb, "ra\n");
	}
	else
		while (first != roota)
			safe_exec_one_stack(reverse_rotate, &roota, &rootb, "rra\n");

	//////////////////////MEDIAN ATTEMPT

	// push_back_to_stack_a(&rootb, &roota);
	// push(&rootb, &roota);
	// printf("pa\n");
	// push(&rootb, &roota);
	// printf("pa\n");
	
	// while (listlen(rootb) > 0)
	// {
	// 	find_all_target_nodes(rootb, roota);
	// 	cheapest_node = find_cheapest_node(rootb);
	// 	prepare_push_protocol(cheapest_node, &rootb, &roota, A);
	// 	push(&rootb, &roota);
	// 	printf("pa\n");
	// 	flush_stacks(rootb, roota);
	// }
	// printf("printing stack a\n");
	// print_list(roota);
	// printf("printing stack b\n");
	// print_list(rootb);
	deallocate(roota);
	deallocate(rootb);
	free(median);
	return (0);
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
int	init_number_list(int argc, char *argv[], t_node **root)
{
	int i;
	int status;
	i = 1;
	while (i < argc)
	{
		status = insert_end(root, ft_atoi(argv[i])); //undo atoi if needed;
		if (!status)
			return (0);
		i++;
	}
	return (1);
}

void	init_node(t_node *new_node)
{
	new_node->instruction = 0;
	new_node->num_of_instructions = 0;
	new_node->target_node = NULL;
}


int insert_end(t_node **root, int value)
{
	t_node *new_node;
	t_node *current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->next = NULL;
	new_node->number = value;
	if ((*root) == NULL)
	{
		*root = new_node;
		new_node->prev = NULL;
		init_node(new_node);
		return (1);
	}    
	current = *root;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
	init_node(new_node);
	return (1);
}





