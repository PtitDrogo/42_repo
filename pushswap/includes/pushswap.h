/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:29:18 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/20 16:46:03 by tfreydie         ###   ########.fr       */
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

// # define RA 1
// # define RB 2
// # define RR 3
// # define RRA 4
// # define RRB 5
// # define RRR 6


# define ROTATE 1
# define REVERSE_ROTATE 2


typedef struct s_node
{
	int             num_of_instructions;
    int             instruction;
    int             number;
    struct s_node	*next;
    struct s_node	*prev;
    struct s_node   *target_node;
}	t_node;

typedef struct s_stacks
{
    int             median;
    t_node          **roota;
    t_node          **rootb;
    
} t_stacks;

//Debugging functions
void	*my_malloc(size_t size);
void	print_list(t_node *root);
//end debugging functions


// int     ft_strncmp(char *s1, char *s2, size_t n);
int    reverse_rotate(t_node **root);
int    swap(t_node *list);
int    rotate(t_node **root);
void   swap_int(int *a, int *b);
int    ss(t_node *roota, t_node *rootb);
int    push(t_node **from, t_node **to);
int    rr(t_node **roota, t_node **rootb);
void    deallocate(t_node *root);
void    free_all_and_exit(t_node *roota, t_node *rootb, t_stacks *pushswap);
void    error_message_exit();
int     listlen(t_node *root);
int    rrr(t_node **roota, t_node **rootb);
char	**ft_split(char const *s, char c);
int     arg_parsing(int argc, char  *argv[], t_stacks *pushswap);
int     push_to_median(t_node **roota, t_node **rootb, t_stacks *pushswap);
int     nicememes(t_node **from, t_node **to, t_stacks *pushswap, int a_or_b);
int     is_sorted(const t_node *roota);
t_node  *get_to_last_node(t_node *root);
void    sort_3(t_node **roota);
t_node  *find_target_node(const t_node *targetless_node, const t_node *root_target_stack);
t_node	*find_smallest_number_node(const t_node *root_target_stack);
void    find_all_target_nodes(t_node *from, t_node *to);
t_node	*find_cheapest_node(const t_node *from);
int	    find_instructions_number(t_node *from, t_node *target_node);
int     calculate_mixed_instructions(t_node *from, t_node *target_node);
int     calculate_with_synergies(int a, int b);
int     instruct_rotate(const t_node *node);
int     instruct_rev_rotate(const t_node *node);

#endif