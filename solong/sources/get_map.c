/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:00:37 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/12 16:04:28 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	    *get_map_array(char *mapname, t_game *game);
static char	    *empty_malloc(void);
static void	    free_two_and_exit(void *tofree_1, void *tofree_2, char *error_message);
static void		ber_check(char *str);

void	get_map_grid(char **argv, t_game *game)
{
	char *map_array;
	
	map_array = get_map_array(argv[1], game);
	if (!map_array)
		perror_and_exit("failed to get map");
	game->map = ft_split(map_array, '\n');
	game->map_double = ft_split(map_array, '\n');
	free(map_array);
	if (!game->map || !game->map_double )
	{	
		game->error_message = "split failed";
		exit_game_protocol(game);
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
		perror_and_exit("failed to open map fd");
	map = empty_malloc();
	new_line = get_next_line(mapfd);
	if (new_line)
		game->map_width = ft_strlen(new_line) - 1;
	game->map_height = 0;
	while (new_line)
	{
		map = ft_strjoin_free_s1(map, new_line);
		if (!map)
			free_two_and_exit((void *)map, (void *)new_line, "malloc failed while reading map");
		free(new_line);
		new_line = get_next_line(mapfd);
		(game->map_height)++;
	}
	if (close(mapfd) == -1)
		free_two_and_exit((void *)map, (void *)new_line, "close failed");
	return (map);
}

static char	*empty_malloc(void)
{
	char *empty_malloc;

	empty_malloc = malloc(sizeof(char));
	if (!empty_malloc)
		perror_and_exit("empty malloc failed");
	empty_malloc[0] = '\0';
	return (empty_malloc);
}

static void	free_two_and_exit(void *tofree_1, void *tofree_2, char *error_message)
{
	free(tofree_1);
	free(tofree_2);
	perror_and_exit(error_message);
}

static void		ber_check(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i - 3] != '.')
		perror_and_exit("not a .ber file");
	return ;
}