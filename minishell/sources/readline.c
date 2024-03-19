/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:35:49 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/19 17:25:48 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


// compile this code with cc readline.c -lreadline

int main(void) {
    char* input;
    while (1) {
        // Display a prompt and read input using readline
        input = readline("myshell> ");
        
        // Check for EOF (Ctrl+D)
        if (!input) {
            break;
        }

        // Skip empty commands
        if (*input) {
            add_history(input); // Add input to history
            printf("You entered: %s\n", input); // Echo back the input
        }

        free(input); // Free the memory readline allocated
    }

    printf("Exit.\n");
    return 0;
}
