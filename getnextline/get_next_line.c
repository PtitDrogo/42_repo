/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:27:36 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/27 13:47:13 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	int			line_status;

	line = secure_init(&line_status, fd);
	if (!line)
		return (free_and_null(line));
	if (buffer[0])
	{
		line = line_check(line, buffer, &line_status);
		if (line_status)
			return (line);
	}
	bytes_read = safe_read(line, buffer, fd);
	while (bytes_read)
	{
		if (bytes_read < 0)
			return (NULL);
		line = line_check(line, buffer, &line_status);
		if (line_status)
			return (line);
		bytes_read = safe_read(line, buffer, fd);
	}
	return (final_check(line));
}

void	*secure_init(int *line_status, int fd)
{
	char	*line;

	if (fd < 0)
		return (NULL);
	*line_status = 1;
	if (BUFFER_SIZE + 1 <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	return (line);
}

char	*line_check(char *line, char *buffer, int *line_status)
{
	int	i;

	line = join_and_free(line, buffer);
	i = 0;
	*line_status = 1;
	if (!line)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
	{
		i++;
		ft_memmove(buffer, &buffer[i], ft_strlen(&buffer[i]) + 1);
		return (line);
	}
	*line_status = 0;
	return (line);
}

int	safe_read(char *line, char *buffer, int fd)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		free(line);
		return (-1);
	}
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

char	*join_and_free(char *line, char *buffer)
{
	char	*new_line;
	int		linelen;
	int		effective_bufferlen;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	effective_bufferlen = i + (buffer[i] == '\n');
	linelen = ft_strlen(line);
	new_line = malloc(sizeof(char) * (linelen + effective_bufferlen + 1));
	if (!new_line)
		return (free_and_null(line));
	new_line[linelen + effective_bufferlen] = '\0';
	i = -1;
	while (++i < linelen)
		new_line[i] = line[i];
	j = 0;
	while (j < effective_bufferlen)
		new_line[i++] = buffer[j++];
	free (line);
	return (new_line);
}
// size_t	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t	i;
// 	char	*copy;

// 	copy = (char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		copy[i] = c;
// 		i++;
// 	}
// 	return (s);
// }

// void	*ft_memmove(void *dest, void *src, int n)
// {
// 	char	*from;
// 	char	*to;
// 	int		i;

// 	from = (char *)src;
// 	to = (char *)dest;
// 	if (from == to || n == 0)
// 		return (dest);
// 	else if (to > from)
// 	{
// 		i = n - 1;
// 		while (i >= 0)
// 		{
// 			to[i] = from[i];
// 			i--;
// 		}
// 	}
// 	else
// 	{
// 		i = -1;
// 		while (++i < n)
// 			to[i] = from[i];
// 	}
// 	return (dest);
// }

// void	*free_and_null(char *line)
// {
// 	free(line);
// 	return (NULL);
// }
// #include <stdio.h>

// #include <fcntl.h>

// int main()
// {
//     int fd = open("test.txt", O_RDONLY);
//     char *line;
//     int i = 1;

//     while((line = get_next_line(fd)))
//     {
//         printf("line %d => %s",i,line);
//         free(line);
//         i++;
//     }
//     // fd = open(NULL, O_RDONLY);
//     // line = get_next_line(fd);
//     // printf("line %d => %s",i,line);
//     return (0);
// }