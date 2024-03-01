/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:09:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/01 20:06:20 by tfreydie         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	*ft_memmove(void *dest, void *src, int n);
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

typedef struct s_node
{
	int             num_of_instructions;
	int             instruction;
	int             number;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node   *target_node;
}	t_node;

typedef int (*f_one)(t_node **, t_node**);
typedef int (*f_two)(t_node **);

int		arg_parsing(int argc, char *argv[], int *medianpointer, t_node **roota);
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

#endif