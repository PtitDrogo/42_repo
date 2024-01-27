#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
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

// char	***handle_script_case(char ***	list_of_commands, int size)
// {
// 	int		i;
// 	int		j;
// 	char	***new_list;
// 	char	**new_script_array;
	
// 	i = 0;
// 	while (list_of_commands[i])
// 	{
// 		if ((list_of_commands[i][0][0] == '.') && (list_of_commands[i][0][0] == '/'))
// 		{
// 			while (list_of_commands[i][j])
// 				j++;
// 			new_script_array = (sizeof(char *) * j + 2);
// 			// j += 2;
// 			j--;
// 			while (j + 2 > 0)
// 			{
// 				list_of_commands[i][j + 2] = list_of_commands[i][j];
// 				j--;
// 			}
// 			list_of_commands[i][j] = "";
// 			list_of_commands[i][j]
// 		}
// 	}
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }

