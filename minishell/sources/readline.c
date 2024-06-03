/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:35:49 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/15 15:57:11 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// typedef struct s_garbage_collect
// {
// 	void				*to_free;
// 	struct s_garbage_collect	*next;
	
// } t_garbage_collect;

// compile this code with cc readline.c -lreadline
int empty_trash(t_garbage_collect *gc);
int	add_to_trash(t_garbage_collect **root, void *to_free);
int	basic_parsing(t_env_node **env_dup_root, t_garbage_collect **gc, char *input);

// simple test that show that add history is cursed and will leak;
// int	main(void)
// {
// 	char* input;
	
// 	input = readline("myshell> ");
// 	add_history(input);
// 	rl_clear_history();
// 	free(input);
// 	// test();
// 	return (0);
// }


int main(int argc, char const *argv[], char **envp) 
{
	t_env_node *env_dup_root;
	t_garbage_collect *gc;
	char	*input;

	
	gc = NULL;
	env_dup_root = NULL;
	if (envp == NULL)
		return (1);
	if (generate_env_llist(&env_dup_root, gc, envp) == 0)
	{
		write(2, "failed to generate env\n", 23);
		empty_trash(gc);
		return (1); // this will be its own function later
	}
	while (1) 
	{
		// Display a prompt and read input using readline
		// printf("Please input a string with the format 'Cmd var'\n");
		input = readline("myshell> ");
		if (add_to_trash(&gc, input) == 0)
			exit(EXIT_FAILURE); // do cleanup later
		if (!input)
			break;
		basic_parsing(&env_dup_root, &gc, input);
		// Check for EOF (Ctrl+D)

		// Skip empty commands
		if (*input) 
		{
			add_history(input); // Add input to history
			// printf("You entered: %s\n", input); // Echo back the input
		}
	}
	
	printf("Exit.\n");
	rl_clear_history();
	empty_trash(gc);
	return 0;
}

int	basic_parsing(t_env_node **env_dup_root, t_garbage_collect **gc, char *input)
{
	char	**split_input;

	split_input = ft_split(input, ' ');
	if (ft_strncmp(split_input[0], "unset", ft_strlen("unset")) == 0)
		unset(*env_dup_root, split_input[1]);
	if (ft_strncmp(split_input[0], "export", ft_strlen("export")) == 0)
	{	
		if (split_input[1] == NULL)
		{
			t_env_node *current = *env_dup_root;
			while (current)
			{
				printf("declare -x %s", current->variable_name);
				if (current->variable)
					printf("=\"%s\"\n", current->variable);
				current  = current->next;
			}
		}
		else
			export(env_dup_root, (void *)split_input[1], gc);
	}
	if (ft_strncmp(split_input[0], "env", ft_strlen("env")) == 0)
		env(*env_dup_root);
	return (0);
}