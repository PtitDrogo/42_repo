/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:27:36 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/13 14:15:00 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
char	*ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);

// char    *get_next_line(int fd)
// {
// 	static char		buffer[BUFFER_SIZE + 1];
// 	char			*line;
// 	int             bytes_read;
// 	int             i;

// 	i = 0;
// 	line = malloc(1);
// 	if (!line)
// 		return (NULL);
// 	line[0] = '\0';

// 	//if not empty buffer
// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	if (bytes_read < 0)
// 		return (NULL);
// 	buffer[BUFFER_SIZE] = '\0';
// 	join_and_free(line, buffer);
// 	//I want to read my buffer until i see a \\n, then somehow remember whats after;
// 	//I want to add whats in my buffer to my line;
	
	
// 	return (line);
// }
char	*join_and_free(char *line, char *buffer)
{
	char	*new_line;
	int	relevantlen;
	int	i;

	
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	relevantlen = ft_strlen(line);
	new_line = malloc(sizeof(char) * (relevantlen + i + 1));
	new_line[relevantlen + i] = '\0';
	i = 0;
	while (i < relevantlen)
	{
		new_line[i] = line[i];
		i++;
	}
	int j = 0;
	relevantlen = ft_strlen(buffer);
	while (j < relevantlen)
	{
		new_line[i] = buffer[j];
		i++;
		j++;
	}
	free (line);
	return (new_line);
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

int main(void)
{
	#include <stdio.h>
	char	*string;
	char	*buffer = " Je suis un buffer";
	char	*new_line;

	string = malloc(sizeof(char) * (2 + 1));
	string[2] = '\0';
	string[1] = 'O';
	string[0] = 'Y';

	new_line = join_and_free(string, buffer);
	// printf("%s\n", new_line);
	free(new_line);


	// char    *current_line;
	// int fd = open("test.txt", 0);
	
	// // current_line = get_next_line(fd);
	// printf("%s\n", get_next_line(fd));
	// if (fd == -1)
	// 	printf("Error");
	// // while (current_line)
	// // {
	// //     printf("%s", current_line);
	// //     current_line = get_next_line(fd);
	// // } 
	// return (0);
}