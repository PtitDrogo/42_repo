/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:40:18 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/01 17:44:45 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	deallocate(t_node *root)
{
	t_node	*memory_to_free;

	if (root)
	{
		while (root->prev)
			root = root->prev;
	}
	while (root)
	{
		memory_to_free = root;
		root = root->next;
		free(memory_to_free);
	}
	return ;
}

void	free_all_and_exit(t_node *roota, t_node *rootb)
{
	deallocate(roota);
	deallocate(rootb);
	exit(EXIT_SUCCESS);
}

void	free_all_and_error_exit(t_node *roota, t_node *rootb)
{
	deallocate(roota);
	deallocate(rootb);
	error_message_exit();
}

void	error_message_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_array(void **array)
{
	int	j;

	j = 0;
	if (array)
	{
		while (array[j])
		{
			free(array[j]);
			j++;
		}
	}
	free(array);
}