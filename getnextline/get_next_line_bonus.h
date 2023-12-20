/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:30:52 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/20 16:35:58 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	*ft_memmove(void *dest, void *src, int n);
char	*join_and_free(char *line, char *buffer);
void	*ft_memset(void *s, int c, size_t n);
int		safe_read(char *line, char *buffer, int buffer_size, int fd);
void	*free_and_null(char *line);
char	*line_check(char *line, char *buffer, int *line_status);
void	*secure_init(int buffer_size, int *line_status, int fd);

#endif