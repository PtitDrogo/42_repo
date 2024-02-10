/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:46 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/10 06:10:20 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


// typedef struct s_node
// {
// 	int				number;
// 	struct s_node   *next;
// 	struct s_node   *prev;
// } t_node;

int		init_number_list(int argc, char *argv[], t_node **root);
int		insert_end(t_node **root, int value);

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
	printf("printinf from start to end\n");
	if (root != NULL)
	{
		while (root->next)
		{
			printf("%i\n", root->number);
			root = root->next;
		}
		printf("%i\n", root->number);
	}
	printf("printinf from end to start\n");
	if (root != NULL)
	{
		while (root->prev)
		{
			printf("%i\n", root->number);
			root = root->prev;
		}
		printf("%i\n", root->number);
	}
	return ;
}

int main(int argc, char *argv[])
{
	int i;
	int status;
	i = 0;
	t_node *roota;
	t_node *rootb;


	
	roota = NULL;
	rootb = NULL;
	status = init_number_list(argc, argv, &roota);
	arg_parsing(argc, argv, roota);
	if (!status)
		return(deallocate(roota), 1);
	push_to_median(&roota, &rootb);
	// // push(rootb, &roota, "pa");
	// push(roota, &rootb, "pb");
	// push(roota, &rootb, "pb");
	// push(roota, &rootb, "pb");
	// push(roota, &rootb, "pb");
	// push(roota, &rootb, "pb");
	// push(roota, &rootb, "pb");
	// push(roota, &rootb, "pb");
	// push(rootb, &roota, "pa");
	// reverse_rotate(&roota, "rra");
	// reverse_rotate(&rootb, "rrb");
	// rotate(&roota, "ra");
	// rotate(&rootb, "rb");
	// rr(&roota, &rootb);
	// ss(roota, rootb);
	// rrr(&roota, &rootb);
	// swap(roota, "sa");

	printf("printing stack a\n");
	print_list(roota);
	printf("printing stack b\n");
	print_list(rootb);
	
	deallocate(roota);
	deallocate(rootb);
	return (0);
}

int	init_number_list(int argc, char *argv[], t_node **root)
{
	int i;
	int status;
	i = 1;
	while (i < argc)
	{
		status = insert_end(root, atoi(argv[i])); //undo atoi if needed;
		if (!status)
			return (0);
		i++;
	}
	return (1);
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
		return (1);
	}    
	current = *root;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
	return (1);
}





