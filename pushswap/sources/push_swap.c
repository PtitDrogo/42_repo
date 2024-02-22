/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:46 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/22 15:51:04 by tfreydie         ###   ########.fr       */
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

void	print_list(t_node *root)
{
	printf("printing from start (root AKA dernier) to end (AKA SOMMET)\n");
	if (root != NULL)
	{
		while (root->next)
		{
			printf("%i \n", root->number);
			// printf("instruction is %i (1 = Rot 2 = RevRot) \n", root->instruction);
			root = root->next;
		}
		printf("%i \n", root->number);
		// printf("instruction is %i (1 = Rot 2 = RevRot) \n", root->instruction);
	}
	// printf("printing from end (AKA SOMMET) to start(root AKA dernier)\n");
	// if (root != NULL)
	// {
	// 	while (root->prev)
	// 	{
	// 		printf("%i\n", root->number);
	// 		root = root->prev;
	// 	}
	// 	printf("%i\n", root->number);
	// }
	return ;
}

int main(int argc, char *argv[])
{
	int status;
	t_node		*roota;
	t_node		*rootb;
	t_stacks	*pushswap;
	t_node *cheapest_node;

	
	pushswap = malloc (sizeof(t_stacks));
	if (!pushswap)
		return (1);
	roota = NULL;
	rootb = NULL;
	status = init_number_list(argc, argv, &roota);
	if (!status)
		return(deallocate(roota), 1);
	arg_parsing(argc, argv, pushswap);
	if (is_sorted(roota))
		printf("list is sorted\n");
	else
		printf("list is not sorted\n");
	push(&roota, &rootb);
	printf("pb\n");
	push(&roota, &rootb);
	printf("pb\n"); //first two initial push
	// push(&roota, &rootb);
	// printf("pb");
	// push(&roota, &rootb);
	// printf("pb");
	// push(&roota, &rootb);
	// printf("pb");
	// push(&roota, &rootb);
	// printf("pb");   
	// push(&roota, &rootb);
	// printf("pb"); 
	
	while (listlen(roota) > 3)
	{	
		printf("printing stack a\n");
		print_list(roota);
		printf("printing stack b\n");
		print_list(rootb);
		// sleep(10);
		find_all_target_nodes(roota, rootb);
		cheapest_node = find_cheapest_node(roota);
		// printf("my cheapest node with value %i has target node whose value is %i", cheapest_node->number, cheapest_node->target_node->number);
		prepare_push_protocol(cheapest_node, &roota, &rootb, A);
		push(&roota, &rootb);
		printf("pb\n");
		flush_stacks(roota, rootb);
	}
	sort_3(&roota);
	while (listlen(rootb) > 0)
	{
		find_all_target_nodes(rootb, roota);
		cheapest_node = find_cheapest_node(rootb);
		prepare_push_protocol(cheapest_node, &rootb, &roota, A);
		push(&rootb, &roota);
		printf("pa\n");
		flush_stacks(rootb, roota);
	}
	
	printf("printing stack a\n");
	print_list(roota);
	printf("printing stack b\n");
	print_list(rootb);
	// printf("printing root of b %i \n", (*rootb).number);
	deallocate(roota);
	deallocate(rootb);
	free(pushswap);
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





