/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:59:55 by tfreydie          #+#    #+#             */
/*   Updated: 2024/01/29 18:02:55 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		count_array_size(char **array);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);

char	***ft_arg_parsing(int argc, char *argv[])
{
	int		i;
	char	***list_of_commands;
	char	*raw_command;
	char	scriptprefix[] = "/bin/bash -c ";
	
	list_of_commands = malloc(sizeof(char **) * (argc - 2));
	//this will be different if here_doc
	if (!list_of_commands)
		return (NULL);
	i = -1;
	while (++i < argc - 3)
	{
		raw_command = argv[i + 2];
		if (raw_command[0] == '.' && raw_command[1] == '/')
		{
			raw_command = ft_strjoin(scriptprefix,raw_command);
			list_of_commands[i] = ft_split(raw_command, ' ');
			free(raw_command);
		}
		else
			list_of_commands[i] = ft_split(raw_command, ' ');
		
	}
	list_of_commands[i] = NULL;
	return (list_of_commands);
}
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		joined[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		joined[i++] = s2[j++];
	}
	joined[i] = '\0';
	return (joined);
}

