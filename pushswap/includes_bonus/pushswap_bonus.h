/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:09:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/05 15:35:58 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*join_and_free(char *line, char *buffer);
void	*ft_memset(void *s, int c, size_t n);
int		safe_read(char *line, char *buffer, int fd);
void	*free_and_null(char *line);
char	*line_check(char *line, char *buffer, int *line_status);
void	*secure_init(int *line_status, int fd);
char	*final_check(char *line);

# define ATOI_ERROR 3000000000
# define SA 1
# define SB 2
# define SS 3
# define RA 4
# define RB 5
# define RR 6
# define RRA 7
# define RRB 8
# define RRR 9
# define PA 10
# define PB 11

typedef struct s_node
{
	int				num_of_instructions;
	int				instruction;
	int				number;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
}	t_node;

void	swap_int(int *a, int *b);
void	init_node(t_node *new_node);
int		init_number_list(int size, int *number_array, t_node **root);
int		arg_parsing(int argc, char **argv, t_node **roota);
long	ft_safe_atoi(const char *nptr);
void	deallocate(t_node *root);
void	free_all_and_exit(t_node *roota, t_node *rootb);
void	free_all_and_error_exit(t_node *roota, t_node *rootb);
void	error_message_exit(void);
void	free_array(void **array);
int		ss(t_node **roota, t_node **rootb);
int		rr(t_node **roota, t_node **rootb);
int		rrr(t_node **roota, t_node **rootb);
int		swap(t_node **head);
int		push(t_node **from, t_node **to);
int		reverse_rotate(t_node **head);
int		rotate(t_node **head);
int		is_sorted(const t_node *heada);
int		listlen(t_node *root);
t_node	*get_to_last_node(t_node *root);
void	free_input_and_error_exit(t_node *roota, t_node *rootb, char *input);
#endif