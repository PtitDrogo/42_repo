/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:11:59 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/10 19:48:53 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	unset(t_env_node *env_dup_root, char *env_to_find);
int	export(t_env_node **root, void *variable, t_garbage_collect **gc);
int	pop(t_env_node *env_dup_root, t_env_node *node_to_pop);

//trying to access a freed pointer no bueno

int main(int argc, char const *argv[], char **envp)
{
    t_env_node *env_dup_root;
	// t_env_node *to_free; // need to introduce my garbage collector later
    t_garbage_collect *gc;
	int	i;
	
	i = -1;
	gc = NULL;
	env_dup_root = NULL;
	if (envp == NULL)
		return (1); //Error handling somehow
	while (envp[++i]) // add condition if export fails
		export(&env_dup_root, (void *)envp[i], &gc);
	//test
	unset(env_dup_root, "DISPLAY=");
	unset(env_dup_root, "IdontExist");
	export(&env_dup_root, "MIAOU=VALGRIND", &gc);
	export(&env_dup_root, "MIAOU2=VALGRIND2", &gc);
	export(&env_dup_root, "MIAOU3=VALGRIND3", &gc);
	unset(env_dup_root, "MIAOU2=");
	//end test
	printf("\n\n\n\n\nhi\n\n\n\n");
	// this loop does memory freeing but it shouldnt after garbage c.
	while (env_dup_root)
	{
		printf("%s\n", env_dup_root->variable);
		// free(env_dup_root->variable);
		// to_free = env_dup_root;
		env_dup_root = env_dup_root->next;
		// free(to_free);
	}
	printf("\n\n\n\n\nhi\n\n\n\n");
	empty_trash(gc);
	return (0);
}

int	unset(t_env_node *env_dup_root, char *env_to_find)
{
	int	len_env;
	t_env_node *current;
	
	current = env_dup_root;
	if (!env_to_find || !env_dup_root) // uh ?
	{
		perror("Environnement does not exist");
		exit(EXIT_FAILURE);
	}
	len_env = ft_strlen(env_to_find);
	while (current)
	{
		if (ft_strnstr(current->variable, env_to_find, len_env))
		{	
			printf("\n\nI found the variable\n\n");
			pop(env_dup_root, current);
			return (1); // here we return the whole string;
		}
		current = current->next;
	}
	return (0); // couldnt find env variable
}

int	pop(t_env_node *env_dup_root, t_env_node *node_to_pop)
{	
	if (!env_dup_root || !node_to_pop)
		return (0); //gotta check later;
	while (env_dup_root->next && env_dup_root->next != node_to_pop)	
		env_dup_root = env_dup_root->next;
	if (env_dup_root->next == NULL)
		return (0); // we couldnt find the node to pop
	printf("\n\n im in poppast the checks\n\n");
	env_dup_root->next = env_dup_root->next->next;
	// free(node_to_pop->variable); // MAYBE NOT NEEDED if we stick to the garbage collector
	node_to_pop->variable = NULL;
	// free(node_to_pop);
	return (1);
}

int	export(t_env_node **root, void *variable, t_garbage_collect **gc)
{
	//NEED TO ADD CONDITION SO I DONT EXPORT THE SAME NAME TWICE
	
	t_env_node	*new_node;
	t_env_node	*current;

	// new_node = malloc(sizeof(t_env_node));
	new_node = malloc_trash(sizeof(t_env_node), gc);
	if (!new_node)
		return (0);
	new_node->next = NULL;
	new_node->variable = ft_strdup(variable); // need to modify ft_strdup somehow;
	add_to_trash(gc, new_node->variable);
	if ((*root) == NULL)
	{
		*root = new_node;
		return (1);
	}
	current = *root;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (1);
}

// int	check_if_variable_exit(t_env_node *root, void *variable)
// {
// 	//this needs to check if the variable already exist, and if 
// 	//so, replace the content after the =;
	
// 	while (root)
// 	{
// 		if ()
		
// 		root = root->next;
// 	}
	
// }