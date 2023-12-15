/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:27:36 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/15 15:03:56 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(char *str);
void    *ft_memmove(void *dest, void *src, int n);
char	*join_and_free(char *line, char *buffer);
void	*ft_memset(void *s, int c, size_t n);
void	*free_and_return_NULL(void *array_to_free);

char    *get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*temp_buff;
	char			*line;
	int				bytes_read;
	int				i;

	i = 0;
	bytes_read = 1;
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	
	if (buffer[0]) //check if buffer exist from previous call;
	{
		line = join_and_free(line, buffer);
		if (!line)
			return (NULL);
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		if (buffer[i] == '\n')
		{
			i++;
			temp_buff = &buffer[i];
			ft_memmove(buffer, temp_buff, ft_strlen(temp_buff) + 1);
			return(line);
		}
		else if (buffer[i] == '\0')
			ft_memset(buffer, 0, BUFFER_SIZE);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while(bytes_read != 0)
	{	
		if (bytes_read <= 0)
			return(free_and_return_NULL(line));
		line = join_and_free(line, buffer);
		if (!line)
			return (NULL);
		i = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0' && i < bytes_read)
			i++;
		if (buffer[i] == '\n' || (i == bytes_read && bytes_read < BUFFER_SIZE))
		{
			i++;
			temp_buff = &buffer[i];
			ft_memmove(buffer, temp_buff, ft_strlen(temp_buff) + 1);
			// ft_memset(&buffer[i] + 1, 0, ));
			return (line);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return(free_and_return_NULL(line));	
	}
	if (buffer[0])
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		return (line);
	}
	if (line[0])
		return(line);
	free(line);
	return (NULL);
}

void	*free_and_return_NULL(void *array_to_free)
{
	free(array_to_free);
	return (NULL);
}
void    *ft_memmove(void *dest, void *src, int n)
{
        char    *from;
        char    *to;
        int             i;

        from = (char *)src;
        to = (char *)dest;
        if (from == to || n == 0)
                return (dest);
        else if (to > from)
        {
                i = n - 1;
                while (i >= 0)
                {
                        to[i] = from[i];
                        i--;
                }
        }
        else
        {
                i = -1;
                while (++i < n)
                        to[i] = from[i];
        }
        return (dest);
}

char	*join_and_free(char *line, char *buffer)
{
	char	*new_line;
	int	linelen;
	int	effective_bufferlen;
	int	i;
	int j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	effective_bufferlen = i + (buffer[i] == '\n');
	linelen = ft_strlen(line);
	new_line = malloc(sizeof(char) * (linelen + effective_bufferlen + 1));
	if(!new_line)
		return(free_and_return_NULL(line));
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
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*copy;

	copy = (char *)s;
	i = 0;
	while (i < n)
	{
		copy[i] = c;
		i++;
	}
	return (s);
}
size_t  ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include <fcntl.h>

// int main()
// {
//     int fd = open("bible.txt", O_RDONLY);
//     char *line;
//     int i = 1;

//     while((line = get_next_line(fd)))
//     {
//         printf("line %d => %s",i,line);
//         free(line);
//         i++;
//     }
//     return (0);
// }