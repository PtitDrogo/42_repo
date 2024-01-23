#include "pipex.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*find_env_var(char **envp, char *env_to_find);
size_t	ft_strlen(const char *s);
void	*free_all(char **array, int j);
char	*ft_strjoin(char const *s1, char const *s2);

int main(int argc, char *argv[], char **envp)
{
    //SEPARATE CMD AND FLAGS
    //GETENV, GET TO PATH,
    //TRY ACCESS ON ALL PATHS
    int i;
    char **possible_paths;
    char *path_env = find_env_var(envp, "PATH");
    char    *current_path;

    i = 0;
    if (!path_env)
    {
        perror("error finding path");
        exit(EXIT_FAILURE);
    }
    printf("path = %s\n", path_env);
    possible_paths = ft_split(path_env, ':'); //THIS IS A MALLOC
    while (possible_paths[i])
    {
        printf("trying possible path = %s\n", possible_paths[i]); 
        current_path = ft_strjoin(possible_paths[i], argv[1]); //Change argv[1] later;
        if (access(current_path, F_OK) == 0)
        {    
            printf("this is the proper path\n");
            printf("proper path is : %s\n", current_path);
            // execve(current_path, argv, envp);
        }
        free(current_path);
        i++;
    }
    free_all(possible_paths, i);
}
int execute_cmd(char    *current_path, char *const argv[], char *const envp[])
{
    // execve(current_path, argv, envp);
    // if (execve("/bin/lsAKAPATH", args, env) == -1) {
    //     perror("execve"); //ARGS is a **char with cmd 1st then flags;
    // }
    return (0);
}

void	*free_all(char **array, int j)
{
	while (j > 0)
	{
		j--;
		if (array[j])
		{
			free(array[j]);
			array[j] = NULL;
		}
	}
	free(array);
	array = NULL;
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
            return (envp[i] + len_env + 1); // + 1 for '=' sign
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
char	*ft_strjoin(char const *s1, char const *s2)
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
