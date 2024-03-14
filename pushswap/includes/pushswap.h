/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:29:18 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/07 16:12:00 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# define ATOI_ERROR 3000000000
# define ROTATE 1
# define REVERSE_ROTATE 2

typedef struct s_node
{
	int				num_of_instructions;
	int				instruction;
	int				number;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
}	t_node;

typedef int	(*t_one)(t_node **, t_node**);
typedef int	(*t_two)(t_node **);

int		reverse_rotate(t_node **root);
int		swap(t_node **list);
int		rotate(t_node **root);
void	swap_int(int *a, int *b);
int		ss(t_node **roota, t_node **rootb);
int		push(t_node **from, t_node **to);
int		rr(t_node **roota, t_node **rootb);
int		rrr(t_node **roota, t_node **rootb);
void	deallocate(t_node *root);
void	free_all_and_error_exit(t_node *roota, t_node *rootb);
void	error_message_exit(void);
int		listlen(t_node *root);
int		arg_parsing(int argc, char *argv[], int *medianpointer, t_node **roota);
int		is_sorted(const t_node *roota);
t_node	*get_to_last_node(t_node *root);
void	sort_3(t_node **roota, t_node **rootb);
void	find_all_target_nodes(t_node *from, t_node *to);
t_node	*find_cheapest_node(const t_node *from);
int		best_of(int a, int b);
int		r_count(const t_node *node);
int		revr_count(const t_node *node);
t_node	*find_smaller_number_node(const t_node *root_target_stack);
void	free_all_and_exit(t_node *roota, t_node *rootb);
int		init_number_list(int size, int *number_array, t_node **root);
long	ft_safe_atoi(const char *nptr);
void	init_node(t_node *new_node);
void	free_array(void **array);
void	prepare_push(t_node *from, t_node **fromroot, t_node **to_root);
int		exec_one(t_two func, t_node **root, t_node **to_free, char *str);
int		exec_two(t_one func, t_node **from, t_node **to, char *str);

#endif