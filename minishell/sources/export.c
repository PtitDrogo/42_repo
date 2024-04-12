/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:11:59 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/12 15:12:12 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	unset(t_env_node *env_dup_root, char *env_to_find);
int	export(t_env_node **root, void *variable, t_garbage_collect **gc);
int	pop(t_env_node *env_dup_root, t_env_node *node_to_pop);

t_env_node *check_if_variable_exist(t_env_node *root, void *variable);
int	is_valid_env_name(char *name);
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
	// unset(env_dup_root, "DISPLAY=");
	// unset(env_dup_root, "IdontExist");
	// export(&env_dup_root, "MIAOU=VALGRIND", &gc);
	// export(&env_dup_root, "MIAOU2=VALGRIND2", &gc);
	// export(&env_dup_root, "MIAOU3=VALGRIND3", &gc);
	// unset(env_dup_root, "MIAOU2=");
	//end test
	printf("\n\n\n\n\nhi\n\n\n\n");
	// this loop does memory freeing but it shouldnt after garbage c.
	while (env_dup_root)
	{
		printf("%s\n", env_dup_root->variable);
		env_dup_root = env_dup_root->next;
	}
	printf("\n\n\n\n\nhi\n\n\n\n");
	empty_trash(gc);
	return (0);
}


//TODO make this universal later
int	pop(t_env_node *env_dup_root, t_env_node *node_to_pop)
{	
	if (!env_dup_root || !node_to_pop)
		return (0); //gotta check later;
	while (env_dup_root->next && env_dup_root->next != node_to_pop)	
		env_dup_root = env_dup_root->next;
	if (env_dup_root->next == NULL)
		return (0); // we couldnt find the node to pop
	env_dup_root->next = env_dup_root->next->next;
	node_to_pop->variable = NULL;
	return (1);
}

int	export(t_env_node **root, void *variable, t_garbage_collect **gc)
{
	t_env_node	*new_node;
	t_env_node	*current;
	t_env_node	*same_name_node;
	
	// if (is_valid_env_name(variable) == 0)
	// 	return (0);
	// same_name_node = check_if_variable_exist(*root, variable);
	// if (same_name_node)
	// {
	// 	same_name_node->variable = ft_strdup(variable);
	// 	add_to_trash(gc, new_node->variable);
	// 	return (1);
	// }
	new_node = malloc_trash(sizeof(t_env_node), gc);
	if (!new_node)
		return (0);
	new_node->next = NULL;
	new_node->variable = ft_strdup(variable); // need to modify ft_strdup somehow unless variable cant be NULL;
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

int	is_valid_env_name(char *name)
{
	//this function checks if the env var name is valid;
	int	i;
	
	if (ft_isalpha(name[0]) == 0 && name[0] != '_')
		return (0);
	i = 1; // we start after the first letter;
	while (name[i])
	{
		if (ft_isalnum(name[i]) == 0 && name[0] != '_')
			return (0);
		i++;
	}
	printf("name is valid !\n");
	return (1);
}

//this function checks if the variable exists already, if it does, it returns the node with the
//variable, otherwise it returns NULL
t_env_node *check_if_variable_exist(t_env_node *root, void *variable)
{
	//VARIABLE IS ALREADY PREPROCESSED TO BE WHATS BEFORE THE =
	
	//this needs to check if the variable already exist, and if 
	//so, replace the content after the =;
	// the tricky part is that "export b" wont replace export "b=test", even with export '';
	
	//if the variable doesnt have a "=" it wont replace anything
	size_t var_len;
	
	if (variable == NULL)
		return (NULL);
	if (is_char_in_str(variable, '=') == 0)
		return (NULL);
	var_len = len_to_char(variable, '=');
	while (root)
	{
		if (len_to_char(variable, '=') == var_len)
		{
			if (ft_strncmp(root->variable, variable, var_len) == 0)
				return (root);
		}
		root = root->next;
	}
	return (NULL);
}

