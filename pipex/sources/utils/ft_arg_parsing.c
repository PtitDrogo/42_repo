#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

char ***    ft_arg_parsing(int argc, char *argv[])
{
	//This function should be calle once, and it will neatly put all the 
	// args into char ** into the commands attribute of my struct
	int i;
	char ***	list_of_commands;
	list_of_commands = malloc(sizeof(char **) * (argc - 2)); //this will be different if here_doc
	if (!list_of_commands)
		return (NULL);
	i = 0;
	while (i < argc - 3)
	{
		list_of_commands[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	list_of_commands[i] = NULL;
	return (list_of_commands);
}

