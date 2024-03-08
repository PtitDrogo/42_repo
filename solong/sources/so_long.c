/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptitdrogo <ptitdrogo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:19:05 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/09 00:57:31 by ptitdrogo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
#include "mlx_int.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

char	*empty_malloc(void);
void	perror_and_exit(char *error_message);
void	free_two_and_exit(void *tofree_1, void *tofree_2, char *error_message);
char	*get_map_array(char *mapname, t_game *game);
void	generate_map(t_game *game, void *mlx_win, void *mlx);
void	init_all(t_game *game, char **argv, void *mlx);
int		exit_game(int keycode, t_game *game);
void	swap_char(char *hero, char *square);
int		is_valid_move(int keycode);
int		click_cross(t_game *game);
void	get_map_grid(char **argv, t_game *game);
char	*get_map_array(char *mapname, t_game *game);


int	main(int argc, char *argv[])
{
	t_game	game;

	//probably reading the map and making sure its good is the best and logical thing to do first;
	if (argc != 2)
	    perror_and_exit("unvalid number of arguments\n");
	game.mlx = mlx_init();
	// if (!mlx_win)
	// 	perror_and_exit("failed to connect to graphical system\n");
	init_all(&game, argv, game.mlx);
	game.mlx_win = mlx_new_window(game.mlx, game.map_width * game.img_width, game.map_height * game.img_height, "Hello world!"); // to define dynamically in initall
	if (!game.mlx_win)
		perror_and_exit("window failed to create\n"); // need to free stuff

	generate_map(&game, game.mlx_win, game.mlx);
	//mlx_key_hook (game.mlx_win, exit_game, (void *)&game);
	mlx_hook(game.mlx_win, KeyPress, KeyPressMask, exit_game, (void *)&game);
	mlx_hook(game.mlx_win, DestroyNotify, StructureNotifyMask, click_cross, (void *)&game);
	mlx_loop(game.mlx);
	// free(game.map);
	
	//PROTOCOL TO FREE
	//ON DETRUIT TOUTE LES IMAGES
	// DETRUIT WINDOW
	// DETRUIT MLX ?
	// FREE MES MALLOCS
}
int	click_cross(t_game *game)
{
	mlx_destroy_image (game->mlx, game->coin);
	mlx_destroy_image (game->mlx, game->wall);
	mlx_destroy_image (game->mlx, game->hero);
	mlx_destroy_image (game->mlx, game->exit);
	mlx_destroy_image (game->mlx, game->floor);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	ft_free_array((void **)game->map);
	exit(EXIT_SUCCESS);
}
int	exit_game(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{	
		mlx_destroy_image (game->mlx, game->coin);
		mlx_destroy_image (game->mlx, game->wall);
		mlx_destroy_image (game->mlx, game->hero);
		mlx_destroy_image (game->mlx, game->exit);
		mlx_destroy_image (game->mlx, game->floor);
		mlx_destroy_window(game->mlx, game->mlx_win);
		mlx_destroy_display(game->mlx);
		ft_free_array((void **)game->map);
		exit(EXIT_SUCCESS);
	}
	printf("hero x = %i y = %i target square x = %i y = %i \n", 
	game->player_xy.x,
	game->player_xy.y,
	game->player_xy.x,
	(game->player_xy.y - 1)
	);
	
	if (is_valid_move(keycode))
	{
		char	*hero;
		char	*target;
		int		x;
		int		y;
		
		int i = 0;
		int j = 0;
		x = game->player_xy.x;
		y = game->player_xy.y;
		hero = &(game->map[y][x]);
		printf("game map variable = %c\n", game->map[y][x]);
		printf("hero variable = %c\n", *hero);
		if (keycode == XK_w || keycode == XK_W)
			y--;
		else if (keycode == XK_s || keycode == XK_S)
			y++;
		else if (keycode == XK_a || keycode == XK_A)
			x--;
		else if (keycode == XK_d || keycode == XK_D)
			x++;
		target = &(game->map[y][x]);
		if ((*target) != '1' && (*target) != 'E')
		{
			swap_char(hero, target);
			game->player_xy.x = x;
			game->player_xy.y = y;
			generate_map(game, game->mlx_win, game->mlx);
		}
		while (game->map[i])
		{
			j = 0;
			while (game->map[i][j])
			{
				write(2, &game->map[i][j], 1);
				j++;
			}
			write(2, "\n", 1);
			i++;	
		}
	}
	return (0);
}
void	swap_char(char *hero, char *square)
{
	*square = *hero;
	*hero = '0';
	return ;
}

int	is_valid_move(int keycode)
{
	static int valid_moves_keycode[] = {XK_a, XK_A, XK_w, XK_W, XK_s, XK_S, XK_d, XK_D, 0};
	int	i;

	i = 0;
	while (valid_moves_keycode[i] != 0)
	{
		if (keycode == valid_moves_keycode[i])
			return (1);
		i++;
	}
	return (0);
}

void	generate_map(t_game *game, void *mlx_win, void *mlx)
{
	int	x;
	int	y;
	
	y = 0;
	// ////DEBUG////
	// write(2, "THIS IS GENERATE MAP MAP\n", 25);
	// int i = 0;
	// int j = 0;
	// while (game->map[i])
	// {
	// 	j = 0;
	// 	while (game->map[i][j])
	// 	{
	// 		write(2, &game->map[i][j], 1);
	// 		j++;
	// 	}
	// 	write(2, "\n", 1);
	// 	i++;	
	// }
	// ///DEBUG///
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, game->wall, game->img_width * x, game->img_height * y);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(mlx, mlx_win, game->floor, game->img_width * x, game->img_height * y);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, game->coin, game->img_width * x, game->img_height * y);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, game->exit, game->img_width * x, game->img_height * y);
			else if (game->map[y][x] == 'P')
			{	
				mlx_put_image_to_window(mlx, mlx_win, game->hero, game->img_width * x, game->img_height * y);
				game->player_xy.x = x;
				game->player_xy.y = y;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	init_all(t_game *game, char **argv, void *mlx)
{
	
	get_map_grid(argv, game);
	game->wall = mlx_xpm_file_to_image(mlx, "./wall.xpm", &(game->img_width), &(game->img_height));
    //check if fail AND check if it exists before destroy
	game->coin = mlx_xpm_file_to_image(mlx, "./coin.xpm", &(game->img_width), &(game->img_height));
	game->floor = mlx_xpm_file_to_image(mlx, "./floor.xpm", &(game->img_width), &(game->img_height));
	game->hero = mlx_xpm_file_to_image(mlx, "./hero.xpm", &(game->img_width), &(game->img_height));
    game->exit = mlx_xpm_file_to_image(mlx, "./end.xpm", &(game->img_width), &(game->img_height));
}
void	get_map_grid(char **argv, t_game *game)
{
	char *map_array;
	
	map_array = get_map_array(argv[1], game); // the function exits itself if theres a failure;
	game->map = ft_split(map_array, '\n');
	if (!game->map)
		exit (EXIT_FAILURE); // TODO CHANGE, AND SEE IF "" breaks the code;
	free(map_array);
	return ;
}

char	*get_map_array(char *mapname, t_game *game)
{
	int		mapfd;
	char	*new_line;
	char	*map;
	
	mapfd = open(mapname, O_RDONLY);
	if (mapfd == -1)
		exit(EXIT_FAILURE); //need to update after i know how to mlx destroy;
	map = empty_malloc();
	new_line = get_next_line(mapfd);
	game->map_width = ft_strlen(new_line) - 1;
	game->map_height = 0;
	while (new_line)
	{
		map = ft_strjoin_free_s1(map, new_line);
		if (!map)
			free_two_and_exit((void *)map, (void *)new_line, "malloc failed");
		free(new_line);
		new_line = get_next_line(mapfd);
		(game->map_height)++;
	}
	close(mapfd); // do i protect close i forgot
	return (map);
}

char	*empty_malloc(void)
{
	char *empty_malloc;

	empty_malloc = malloc(sizeof(char));
	if (!empty_malloc)
		perror_and_exit("malloc failed");// gotta update this !
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
