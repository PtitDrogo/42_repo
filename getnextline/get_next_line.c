/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:27:36 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/13 17:08:17 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
char	*ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
void    *ft_memmove(void *dest, void *src, int n);
char	*join_and_free(char *line, char *buffer);

char    *get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*temp_buff;
	char			*line;
	int             bytes_read;
	int             i;

	i = 0;
	bytes_read = 1;
	line = malloc(1);
	if (!line)
		return (NULL);
	
	while (no_newline(buffer) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
	}
		line = join_and_free(line, buffer);
	}	
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
	{
		temp_buff = &buffer[i];
		ft_memmove(buffer, temp_buff, i);
	}
	
	return (line);
	//I want to read my buffer until i see a \\n, then somehow remember whats after;
	//I want to add whats in my buffer to my line;
	
	
	return (line);
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
	int	relevantlen;
	int	i;
	int j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	relevantlen = ft_strlen(line);
	new_line = malloc(sizeof(char) * (relevantlen + i + 1));
	if(!new_line)
	{
		free(line);
		return (NULL);
	}
	new_line[relevantlen + i] = '\0';
	i = -1;
	while (++i < relevantlen)
		new_line[i] = line[i];
	j = 0;
	relevantlen = ft_strlen(buffer);
	while (j < relevantlen)
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
size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = -1;
	j = 0;
	joined = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined)
		return (NULL);
	while (++i < s1_len)
		joined[i] = s1[i];
	while (j < s2_len)
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}
size_t  ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include <stdio.h>
int main(void)
{
	char    *current_line;
	int fd = open("test.txt", 0);
	int i = 0;
	
	if (fd == -1)
		printf("Error");
	while (i < 1)
	{
	    printf("%s\n", get_next_line(fd));
		i++;
	} 
	return (0);
}