/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:35:49 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/10 17:33:14 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_garbage_collect
{
	void				*to_free;
	struct s_garbage_collect	*next;
	
} t_garbage_collect;

// compile this code with cc readline.c -lreadline
int empty_trash(t_garbage_collect *gc);
int	add_to_trash(t_garbage_collect **root, void *to_free);

//simple test that show that add history is cursed and will leak;
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


int main(void) {
	char* input;
	t_garbage_collect *gc;

	gc = NULL;
	while (1) 
	{
		// Display a prompt and read input using readline
		input = readline("myshell> ");
		if (add_to_trash(&gc, (void *)input) == 0)
			exit(EXIT_FAILURE); // do cleanup later
		
		// Check for EOF (Ctrl+D)
		if (!input)
			break;

		// Skip empty commands
		if (*input) 
		{
			add_history(input); // Add input to history
			printf("You entered: %s\n", input); // Echo back the input
		}
	}
	
	printf("Exit.\n");
	rl_clear_history();
	empty_trash(gc);
	return 0;
}

// int	add_to_trash(t_garbage_collect **root, void *to_free)
// {
// 	t_garbage_collect	*new_node;
// 	t_garbage_collect	*current;

// 	new_node = malloc(sizeof(t_garbage_collect));
// 	if (!new_node)
// 		return (0);
// 	new_node->next = NULL;
// 	new_node->to_free = to_free;
// 	if ((*root) == NULL)
// 	{
// 		*root = new_node;
// 		return (1);
// 	}
// 	current = *root;
// 	while (current->next)
// 		current = current->next;
// 	current->next = new_node;
// 	return (1);
// }

// int empty_trash(t_garbage_collect *gc)
// {
// 	t_garbage_collect *tmp_to_free;
	
// 	while (gc)
// 	{
// 		free(gc->to_free);
// 		tmp_to_free = gc;
// 		gc = gc->next;
// 		free(tmp_to_free);
// 	}
// 	return (1);
// }
