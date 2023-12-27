/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:01:45 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/27 13:42:49 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>

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

#endif
