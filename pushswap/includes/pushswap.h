/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:29:18 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/15 19:22:13 by tfreydie         ###   ########.fr       */
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

typedef struct s_node
{
	int             number;
    struct s_node	*next;
    struct s_node	*prev;
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
void    reverse_rotate(t_node **root, char *version);
void    swap(t_node *list, char *version);
void    rotate(t_node **root, char *version);
void    swap_int(int *a, int *b);
void    ss(t_node *roota, t_node *rootb);
void    push(t_node **from, t_node **to, char *version);
void    rr(t_node **roota, t_node **rootb);
void    deallocate(t_node *root);
void    free_all_and_exit(t_node *roota, t_node *rootb, t_stacks *pushswap);
void    error_message_exit();
int     listlen(t_node *root);
void    rrr(t_node **roota, t_node **rootb);
char	**ft_split(char const *s, char c);
int     arg_parsing(int argc, char  *argv[], t_stacks *pushswap);
int     *sort_array(int *array, int array_size);
int     push_to_median(t_node **roota, t_node **rootb, t_stacks *pushswap);
int     nicememes(t_node **from, t_node **to, t_stacks *pushswap, int a_or_b);
int     is_sorted(t_node *roota);
t_node  *get_to_last_node(t_node *root);
void    sort_3(t_node **roota);


#endif