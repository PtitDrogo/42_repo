#include "pipex.h"
#include <stdio.h>


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
    int pipes = argc - 2;
    int fd[pipes][2];
    pid_t child_ids[argc - 1];
    int i = 0;
    int current_pipe = 0;
    int status;
    printf("argc number = %i\n", argc);
    while (i < pipes)
    {
        if (pipe(fd[i]) == -1) 
            {
                perror("Pipe creation failed");
                exit(1);
            }
        i++;
    }
    i = 1;
    while (i < argc)
    {
        child_ids[i - 1] = fork();
        if (child_ids[i - 1] == 0)
        {
            if (i == 1)
            {    
                write(2, "i == 1\n", 7);
                dup2(fd[current_pipe][1], STDOUT_FILENO);
            }
            else if ((i + 1) == argc)
            {    
                write(2, "i + 1 == argc\n", 14);
                ft_putnbr_fd(i, 2);
                write(2, "\n", 1);
                dup2(fd[current_pipe][0], STDIN_FILENO);
            }
            else
            {
                write(2, "You should not see me\n", 22);
                dup2(fd[current_pipe][1], STDOUT_FILENO);
                dup2(fd[current_pipe][0], STDIN_FILENO);
            }
            int j = 0;
            while (j < pipes)
            {
                close(fd[j][0]);
                close(fd[j][1]);
                j++;
            }
            write(2, "exec\n", 5);
            execlp(argv[i], argv[i], NULL);
            perror("Error executing parent process");
            exit(EXIT_FAILURE);
        }
        if (child_ids[i - 1] > 0)
        {
            if (i != 1 && i + 1 != argc)
                current_pipe++;
            
        }
        i++;
    }
    i = 0;
    while (i < argc - 1)
    {
        // sleep(5);
        waitpid(child_ids[i], &status, WNOHANG);
        write(2, "waited for child : ", 19);
        ft_putnbr_fd(child_ids[i], 2);
        write(2, "\n", 1);
        i++;
    }
    i = 0;
    while (i < pipes)
    {
        close(fd[i][0]);
        close(fd[i][1]);
        i++;
    }
    return (0);
}