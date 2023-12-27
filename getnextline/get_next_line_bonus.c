/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:35:14 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/27 13:50:09 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	int			line_status;

	line = secure_init(&line_status, fd);
	if (!line)
		return (free_and_null(line));
	if (buffer[fd][0])
	{
		line = line_check(line, buffer[fd], &line_status);
		if (line_status)
			return (line);
	}
	bytes_read = safe_read(line, buffer[fd], fd);
	while (bytes_read)
	{
		if (bytes_read < 0)
			return (NULL);
		line = line_check(line, buffer[fd], &line_status);
		if (line_status)
			return (line);
		bytes_read = safe_read(line, buffer[fd], fd);
	}
	return (final_check(line));
}

void	*secure_init(int *line_status, int fd)
{
	char	*line;

	if (fd > FOPEN_MAX || fd < 0)
		return (NULL);
	if (BUFFER_SIZE + 1 <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	*line_status = 1;
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
