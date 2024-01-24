#include "pipex.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	*free_all_all(char ***array, int j);
int main(int argc, char *argv[], char **envp)
{
    //THIS IS BROKEN AND SO IS MY BRAIN WILL DO LATER
    int i;
    t_command_line cmd_line;
    
    cmd_line.commands = malloc(sizeof(char **) * (argc + 1)); //this will be different in actual code
    if (!cmd_line.commands)
        return (1); //NULL in real code;
    i = 0;
    while (argv[i])
    {
        cmd_line.commands[i] = ft_split(argv[i], ' ');
        printf("nom de la commande : %s\n", cmd_line.commands[i][0]);
        printf("premier flag : %s\n", cmd_line.commands[i][1]);
        // printf("deuxieme flag : %s\n", cmd_line.commands[i][2]);
        i++;
    }
    cmd_line.commands[i] = NULL;
    //EXECVE WOULD BE HERE
    free_all_all(cmd_line.commands, i);
    return (0);
}

void	*free_all_all(char ***array, int j)
{
	printf("hi im in\n");
    int i;

    while (j > 0)
	{
		printf("hi im in and j = %i\n", j);
        i = 0;
        j--;
		if (array[j])
		{
            while (array[j][i])
            {
                printf("hi im in and i = %i and what im about to free is %s\n", i, array[j][i]);
                free(array[j][i]);
                i++;
            }
        }
        free(array[j]);
    }
    free(array);
    printf("hi im out\n");
	return (NULL);
}