/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:55:13 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/09 16:11:40 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
char	**dup_envp(char **envp);
int		find_n_destroy_env_variable(char **envp, char *env_to_find);
int		unset(char *to_unset, char **envp);

int main(int argc, char const *argv[], char **envp)
{
    char **envp_dup;
    // t_env_node env_list_root;
        
    envp_dup = dup_envp(envp);
    for(int i = 0; envp_dup[i] != NULL; i++)
    {
        printf("%s\n", envp_dup[i]);
    }
	printf("\n\n\n");
	unset("LD_PRELOAD=", envp_dup);
	for(int i = 0; envp_dup[i] != NULL; i++)
    {
        printf("%s\n", envp_dup[i]);
    } 	
	int i = 0;
	while (envp_dup[i + 1]) // this sucks if we unset the last one;
	{
        free(envp_dup[i]);
		i++;
	}
	free(envp_dup);
    return (0);
}

int unset(char *to_unset, char **envp)
{
	int i;
	
	i = 0;
	if (find_n_destroy_env_variable(envp, to_unset) == 0)
		return (1); //couldnt find var;
	while (envp[i]) //the first NULL will be the destroyed var;
		i++;
	i++;
	while (envp[i])
	{
		envp[i - 1] = envp[i];
		i++;
	}
	printf("\n\n null = %s \n\n", envp[i]);
	return (1);
}

int	find_n_destroy_env_variable(char **envp, char *env_to_find)
{
	int	i;
	int	len_env;

	if (!env_to_find || !envp || !envp[0]) // uh ?
	{
		perror("Environnement does not exist");
		exit(EXIT_FAILURE);
	}
	len_env = ft_strlen(env_to_find);
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], env_to_find, len_env))
		{	
			printf("I found the variable\n");
			free(envp[i]);
			envp[i] = NULL;
			return (1); // here we return the whole string;
		}
		i++;
	}
	return (0); // couldnt find env variable
}

char **dup_envp(char **envp)
{
    int i;
    char **envp_dup;
    
    i = 0;
    if (envp == NULL)
        return (NULL);
    while (envp[i])
        i++;
    envp_dup = malloc(sizeof(char *) * (i + 1));
	if (!envp_dup)
		exit(EXIT_FAILURE); // do exit protocol later
    i = 0;
    while (envp[i])
    {
        envp_dup[i] = ft_strdup(envp[i]); // change function for malloc fail;
        i++;
    }
    envp_dup[i] = NULL;
    return (envp_dup);
}