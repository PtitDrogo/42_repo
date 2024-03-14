/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:00:37 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/13 18:06:00 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char		*get_map_array(char *mapname, t_game *game);
static char		*empty_malloc(void);
static void		free_two_and_exit(void *tofree_1, void *tofree_2, char *err);
static void		ber_check(char *str);

void	get_map_grid(char **argv, t_game *game)
{
	char	*map_array;

	map_array = get_map_array(argv[1], game);
	if (!map_array)
		perror_and_exit("Error\nfailed to get map");
	game->map = ft_split(map_array, '\n');
	game->map_double = ft_split(map_array, '\n');
	free(map_array);
	if (!game->map || !game->map_double)
	{
		game->error_message = "Error\nsplit failed";
		exit_game(game);
	}
	return ;
}

static char	*get_map_array(char *mapname, t_game *game)
{
	int		mapfd;
	char	*new_line;
	char	*map;

	ber_check(mapname);
	mapfd = open(mapname, O_RDONLY);
	if (mapfd == -1)
		perror_and_exit("Error\nfailed to open map fd");
	map = empty_malloc();
	new_line = get_next_line(mapfd);
	if (new_line)
		game->map_width = ft_strlen(new_line) - 1;
	game->map_height = 0;
	while (new_line)
	{
		map = ft_strjoin_free_s1(map, new_line);
		if (!map)
			free_two_and_exit((void *)map, (void *)new_line, "Error\nmalloc");
		free(new_line);
		new_line = get_next_line(mapfd);
		(game->map_height)++;
	}
	if (close(mapfd) == -1)
		free_two_and_exit((void *)map, (void *)new_line, "Error\nclose failed");
	return (map);
}

static char	*empty_malloc(void)
{
	char	*empty_malloc;

	empty_malloc = malloc(sizeof(char));
	if (!empty_malloc)
		perror_and_exit("Error\nempty malloc failed");
	empty_malloc[0] = '\0';
	return (empty_malloc);
}

static void	free_two_and_exit(void *tofree_1, void *tofree_2, char *err)
{
	free(tofree_1);
	free(tofree_2);
	perror_and_exit(err);
}

static void	ber_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	if (s[i] != 'r' || s[i - 1] != 'e' || s[i - 2] != 'b' || s[i - 3] != '.')
		perror_and_exit("Error\nnot a .ber file");
	return ;
}
