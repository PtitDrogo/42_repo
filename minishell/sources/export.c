/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:11:59 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/09 16:15:48 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	find_n_destroy_env_variable(char **envp, char *env_to_find);


int main(int argc, char const *argv[], char **envp)
{
    t_env_node env_dup_root;
    
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