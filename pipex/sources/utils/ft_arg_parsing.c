#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

void	*free_all_all(char ***array, int j);
char ***    ft_arg_parsing(int argc, char *argv[], t_command_line  *cmd_line)
{
	//This function should be calle once, and it will neatly put all the 
	// args into char ** into the commands attribute of my struct
	int i;
	char ***	list_of_commands;
	list_of_commands = malloc(sizeof(char **) * (argc + 1)); //this will be different in actual code
	if (!list_of_commands)
	{	
		cmd_line->is_err = 1;
		return (NULL);
	}
	i = 2;
	while (i < argc - 1)
	{
		list_of_commands[i] = ft_split(argv[i], ' ');
		// printf("nom de la commande : %s\n", list_of_commands[i][0]);
		// printf("premier flag : %s\n", list_of_commands[i][1]);
		// printf("deuxieme flag : %s\n", list_of_commands[i][2]);
		i++;
	}
	list_of_commands[i] = NULL;
	// ft_env_parsing(argc, argv, envp);
	//EXECVE WOULD BE HERE
	return (list_of_commands);
	//Calling programm would do the free;
	free_all_all(list_of_commands, i);
}

void	*free_all_all(char ***array, int j)
{
	int i;

	while (j > 0)
	{
		i = 0;
		j--;
		if (array[j])
		{
			while (array[j][i])
			{
				free(array[j][i]);
				i++;
			}
		}
		free(array[j]);
	}
	free(array);
	return (NULL);
}