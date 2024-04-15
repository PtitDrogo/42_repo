/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:35:49 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/15 12:52:37 by tfreydie         ###   ########.fr       */
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

