#include "pipex.h"
#include <stdio.h>

//MARCHE PAS POUR RAISON INCONNU MAIS PAS LA BONNE METHODE ANYWAY

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		digit = n + '0';
		write(fd, &digit, 1);
		return ;
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

int main(int argc, char *argv[])
{
    int fd[2];
    int i = 1;
    int status;
    printf("argc number = %i\n", argc);

    if (pipe(fd) == -1) 
        {
            perror("Pipe creation failed");
            exit(1);
        }
    while (i < argc)
    {
        int child_id = fork();
        if (child_id == 0)
        {
            if (i == 1)
            {    
                write(2, "i == 1\n", 7);
                dup2(fd[1], STDOUT_FILENO);
            }
            else if ((i + 1) == argc)
            {    
                write(2, "i + 1 == argc\n", 14);
                dup2(fd[0], STDIN_FILENO);
            }
            else
            {
                dup2(fd[1], STDOUT_FILENO);
                dup2(fd[0], STDIN_FILENO);
            }
            close(fd[0]);
            close(fd[1]);
            write(2, "exec\n", 5);
            execlp(argv[i], argv[i], NULL);
            perror("Error executing parent process");
            exit(EXIT_FAILURE);
        }
        else if (child_id > 0)  
        {    
            waitpid(child_id, &status, 0);
            write(2, "waited\n", 7);
            ft_putnbr_fd(child_id, 2);
        }
        i++;
    }
    close(fd[0]);
    close(fd[1]);
    return (0);

}