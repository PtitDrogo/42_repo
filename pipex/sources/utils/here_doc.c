/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:47:43 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/01 18:57:33 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line.h"

int		ft_strncmp(char *s1, char *s2, size_t n);
void	reopen_heredoc(t_cmd *cmd_line);
void	set_heredoc(char *arg, t_cmd *cmd_line);
void	here_doc(int argc, char *delimiter, t_cmd *cmd_line)
{
	char	*input;
	int     here_doc_tmp_fd;
	
	here_doc_tmp_fd = open(".ft_heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (here_doc_tmp_fd < 0)
		perror_and_exit("failed to open heredoc", cmd_line);
	while (1)
	{
		write(1, "heredoc> ", 9);
		input = get_next_line(0);
		if (!input)
			perror_and_exit("failed to get line from heredoc", cmd_line);
		if (!ft_strncmp(input, delimiter, ft_strlen(delimiter) + 1))
			break;
		write(here_doc_tmp_fd, input, ft_strlen(input));
		// printf("just added this to ft_heredoc : %s", input);
		// write(file, "\n", 1); MAYBE THIS IS NEEDED
		free (input);
	}
	free(input);
	if (close(here_doc_tmp_fd) == - 1)
			perror_and_exit("failed to close temp heredoc", cmd_line);
	reopen_heredoc(cmd_line);
	return ;
}

void	reopen_heredoc(t_cmd *cmd_line)
{
	cmd_line->infile = open(".heredoc_tmp", O_RDONLY);
	if (cmd_line->infile < 0)
	{
		if (unlink(".heredoc_tmp") == -1)
		{	
			perror("failed to unlink heredoc after heredoc failed to open");
			exit(errno);
		}
		perror_and_exit("failed to open heredoc", cmd_line);
	}
}

void	set_heredoc(char *arg, t_cmd *cmd_line)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
		cmd_line->here_doc = 1;
	else
		cmd_line->here_doc = 0;
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < n)
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}



