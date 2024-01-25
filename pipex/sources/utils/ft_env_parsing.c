#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*find_env_var(char **envp, char *env_to_find);
size_t	ft_strlen(const char *s);
void	*free_all(char **array, int j);
char	*ft_strjoin_and_add(char const *s1, char const *s2, char c);

char * ft_env_parsing(int argc, char *argv[], char **envp, t_command_line  *cmd_line, int command_index)
{
	//THIS FUNCTION, AT ITS CORE, TEST THE COMMAND AND RETURN VALID PATH
    int i;
    // char **possible_paths;
    // char *path_env = find_env_var(envp, "PATH=");
    char    *current_path;

    i = 0;

    // printf("path = %s\n", path_env);
    // possible_paths = ft_split(path_env, ':');
	// if (possible_paths[0])
	// {
	// 	free(possible_paths);
	// 	perror("failed to split PATH");
	// 	exit(EXIT_FAILURE);
	// }
    while (cmd_line->possible_paths[i])
    {
        // printf("trying possible path = %s\n", possible_paths[i]); 
        current_path = ft_strjoin_and_add(cmd_line->possible_paths[i], cmd_line->commands[command_index][0], '/'); //Change argv[1] later;
		if (!current_path)
		{
			int j = 0;
			// free possible path variable without index
			while (cmd_line->possible_paths[j])
			{
				if (cmd_line->possible_paths[j])
					free(cmd_line->possible_paths[j]);
				j++;
			}
			free(cmd_line->possible_paths);
			// free posible path variable
			free(cmd_line->child_ids);
			free_all_all(cmd_line->commands, cmd_line->command_number);
			free_all_fds(cmd_line->pipes, cmd_line->fd);
			perror("failed to create valid path");
			exit(EXIT_FAILURE);
		}
		printf("current_path = %s\n", current_path);
		if (access(current_path, F_OK) == 0)
        {    
            free_all(cmd_line->possible_paths, i);
			// printf("this is the proper path\n");
            printf("proper path is : %s\n", current_path);
			return (current_path);
        }
        free(current_path);
        i++;
    }
	cmd_line->is_err = 1;
    free_all(cmd_line->possible_paths, i);
	return (NULL);
}

void	*free_all(char **array, int j)
{
	while (j > 0)
	{
		j--;
		if (array[j])
			free(array[j]);
	}
	free(array);
	return (NULL);
}
char	*find_env_var(char **envp, char *env_to_find)
{
    int i;
    char    *current_line;
    int len_env;

    if (!env_to_find | !envp)
        return (NULL);
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
