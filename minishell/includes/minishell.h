/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:14:17 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/12 14:58:33 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



///------------------------Includes------------------------///
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


///------------------------Structs------------------------///

typedef struct s_env_node {

	struct s_env_node	*next;
	char				*variable;
	bool				is_set_value; //isthere an equal sign
} t_env_node;

typedef struct s_garbage_collect
{
	void						*to_free;
	struct s_garbage_collect	*next;
	
} t_garbage_collect;

///------------------------Functions------------------------///

//garbage collector
int		add_to_trash(t_garbage_collect **root, void *to_free);
void    *malloc_trash(int size, t_garbage_collect **gc);
int 	empty_trash(t_garbage_collect *gc);

//BUILT INS
int	unset(t_env_node *env_dup_root, char *env_to_find);

//UTILS
size_t	len_to_char(char *str, char c);
int	is_char_in_str(char *str, char c);
int	pop(t_env_node *env_dup_root, t_env_node *node_to_pop);

///------------------------Libft------------------------///
char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int	ft_isalpha(int c);
int	ft_isalnum(int c);
int	ft_isdigit(int c);
int	ft_strncmp(char *s1, char *s2, size_t n);