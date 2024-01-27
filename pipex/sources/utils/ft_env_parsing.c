#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*find_env_variable(char **envp, char *env_to_find);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_and_add(char const *s1, char const *s2, char c);
char	*ft_strdup_secure(const char *src);
char	**append_to_array(char **current_array, char *to_add);

char * find_valid_path(t_cmd  *cmd_line)
{
    int		i;
    char	*current_path;
    
	i = 0;  
	current_path = ft_strdup_secure(cmd_line->commands[cmd_line->current_process][0]);
	printf("current_path = %s\n", current_path);
	if (!current_path)
		free_all_and_exit(cmd_line, "failed to create valid path");
	else if (access(current_path, X_OK) == 0)
		return (current_path);
	else
		free(current_path);
	while (cmd_line->possible_paths[i])
    {
        current_path = ft_strjoin_and_add(cmd_line->possible_paths[i], cmd_line->commands[cmd_line->current_process][0], '/');
		if (!current_path)
			free_all_and_exit(cmd_line, "failed to create valid path");
		if (access(current_path, X_OK) == 0)
			return (current_path);
        free(current_path);
        i++;
    }
	return (NULL);
}


char	*find_env_variable(char **envp, char *env_to_find)
{
    int i;
    int len_env;

    if (!env_to_find || !envp || !envp[0])
    {    
		perror("Environnement does not exist");
		exit(EXIT_FAILURE);
	}
	len_env = ft_strlen(env_to_find);
    i = 0;
    while (envp[i])
    {
        if (ft_strnstr(envp[i], env_to_find, len_env))
            return (envp[i] + len_env);
        i++;
    }
    return (NULL);
}
char	**append_to_array(char **current_array, char *to_add)
{
	int		i;
	char	**new_array;

	i = 0;
	while (current_array[i])
		i++;
	new_array = malloc(sizeof(char *) * (i + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	while (current_array[i])
	{
		new_array[i] = current_array[i];
		i++;
	}
	new_array[i] = to_add;
	i++;
	new_array[i] = NULL;
	free(current_array);
	return (new_array);
}
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j] != '\0' && j < len)
	{
		i = 0;
		if (big[j] == little[i])
		{
			while (big[i + j] == little[i] && big[i + j] && (j + i) < len)
			{
				i++;
			}
			if (little[i] == '\0')
				return ((char *)(big + j));
		}
		j++;
	}
	return (NULL);
}
char	*ft_strjoin_and_add(char const *s1, char const *s2, char c)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1 + sizeof(c)));
	if (!joined)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i] = c;
	i++;
	while (j < ft_strlen(s2))
	{
		joined[i++] = s2[j++];
	}
	joined[i] = '\0';
	return (joined);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup_secure(const char *src)
{
	int		length;
	int		i;
	char	*dest;

	if (!src)
		return (NULL);
	i = 0;
	length = 0;
	while (src[length] != '\0')
	{
		length++;
	}
	dest = malloc(sizeof(char) * length + 1);
	if (!dest)
		return (NULL);
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[length] = '\0';
	return (dest);
}