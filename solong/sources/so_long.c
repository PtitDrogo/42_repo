/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:19:05 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/07 14:57:28 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
#include "mlx_int.h"
#include "mlx.h"



char	*empty_malloc(void);
void	perror_and_exit(char *error_message);
void	free_two_and_exit(void *tofree_1, void *tofree_2, char *error_message);
char	*magic(char *mapname);
void	parse_map(t_game *game, void *mlx_win, void **mlx);
void	init_all(t_game *game, char **argv, void **mlx);

int	main(int argc, char *argv[])
{
	void	*mlx_win;
	void	*mlx;
	t_game	game;

	if (argc != 2)
	    perror_and_exit("unvalid number of arguments");
	mlx = mlx_init();
	init_all(&game, argv, &mlx);
	mlx_win = mlx_new_window(mlx, 3000, 2000, "Hello world!"); // to define dynamically in initall
	parse_map(&game, mlx_win, &mlx);
	printf("map = \n%s\n", game.map);
	if (!mlx_win)
		perror_and_exit("window failed to create"); // need to free stuff
	mlx_put_image_to_window(mlx, mlx_win, game.coins, 64, 64);
	mlx_loop(mlx);
	free(game.map);
}
void	parse_map(t_game *game, void *mlx_win, void **mlx)
{
	int	x;
	int	y;
	int	i;
	
	x = 0;
	y = 0;
	i = 0;
	printf("game map = %s\n", game->map);
	printf("game map first char = %c\n", game->map[i]);
	while (game->map[i])
	{
		write(2, "hey !", 6);
		if (game->map[i] == '1')
			mlx_put_image_to_window(*mlx, mlx_win, game->wall, game->width * x, game->height * y);
		if (game->map[i] == '0')
			mlx_put_image_to_window(*mlx, mlx_win, game->floor, game->width * x, game->height * y);
		else if (game->map[i] == 'C')
			mlx_put_image_to_window(*mlx, mlx_win, game->coins, game->width * x, game->height * y);
		else if (game->map[i] == 'E')
			mlx_put_image_to_window(*mlx, mlx_win, game->exit, game->width * x, game->height * y);
		else if (game->map[i] == 'P')
			mlx_put_image_to_window(*mlx, mlx_win, game->hero, game->width * x, game->height * y);
		else if (game->map[i] == '\n')
		{	
			y++;
			x = 0;
		}
		i++;
		x++;
		printf("I am in loop i = %i x = %i y = %i width = %i height = %i\n", i, x, y, game->width, game->height);
	}
	return ;
}
void	init_all(t_game *game, char **argv, void **mlx)
{
	game->map = magic(argv[1]);
	game->wall = mlx_xpm_file_to_image(*mlx, "./wall.xpm", &(game->width), &(game->height));
    game->coins = mlx_xpm_file_to_image(*mlx, "./coins.xpm", &(game->width), &(game->height));
    game->floor = mlx_xpm_file_to_image(*mlx, "./floor.xpm", &(game->width), &(game->height));
    game->hero = mlx_xpm_file_to_image(*mlx, "./hero.xpm", &(game->width), &(game->height));
    game->exit = mlx_xpm_file_to_image(*mlx, "./end.xpm", &(game->width), &(game->height));
}

char	*magic(char *mapname)
{
	int		mapfd;
	char	*new_line;
	char	*map;
	mapfd = open(mapname, O_RDONLY);
	if (mapfd == -1)
		exit(EXIT_FAILURE);
	
	map = empty_malloc();
	new_line = get_next_line(mapfd);
	while (new_line)
	{
		map = ft_strjoin_free_s1(map, new_line);
		if (!map)
			free_two_and_exit((void *)map, (void *)new_line, "malloc failed");
		free(new_line);
		new_line = get_next_line(mapfd);
	}
	return (map);
}

char	*empty_malloc(void)
{
	char *empty_malloc;

	empty_malloc = malloc(sizeof(char));
	if (!empty_malloc)
		perror_and_exit("malloc failed");
	empty_malloc[0] = '\0';
	return (empty_malloc);
}

void	perror_and_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	free_two_and_exit(void *tofree_1, void *tofree_2, char *error_message)
{
	free(tofree_1);
	free(tofree_2);
	perror_and_exit(error_message);
}
