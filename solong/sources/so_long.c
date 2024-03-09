/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:19:05 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/09 19:05:06 by tfreydie         ###   ########.fr       */
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
void	init_all(t_game *game, char **argv);
int		key_pressed(int keycode, t_game *game);
int		swap_char(char *hero, char *square, t_game *game);
int		is_move(int keycode);
void	get_map_grid(char **argv, t_game *game);
char	*get_map_array(char *mapname, t_game *game);
int		exit_game_protocol(t_game *game);
int		is_map_coinless(char **map);
void	handle_move_key(int keycode, int *x, int *y);
void	generate_square(t_game *game, void *mlx_win, void *mlx,int x, int y);

int	is_map_valid(char **map);
int	map_items_check(char **map);
void	process_char(char c, int items[3]);
int	map_rectangle_check(char **map);
int	map_walls_check(char **map);
int	is_char_correct(char c);
int	map_char_check(char **map);

int	main(int argc, char *argv[])
{
	t_game	game;

	//probably reading the map and making sure its good is the best and logical thing to do first;
	if (argc != 2)
	    perror_and_exit("unvalid number of arguments\n");
	init_all(&game, argv);
	generate_map(&game, game.mlx_win, game.mlx);
	mlx_hook(game.mlx_win, KeyPress, KeyPressMask, key_pressed, (void *)&game);
	mlx_hook(game.mlx_win, DestroyNotify, StructureNotifyMask, exit_game_protocol, (void *)&game);
	mlx_loop(game.mlx);
	
	// PROTOCOL TO FREE
	// ON DETRUIT TOUTE LES IMAGES
	// DETRUIT WINDOW
	// DETRUIT MLX ?
	// FREE MES MALLOCS
}

int	is_map_valid(char **map)
{
	if (!map)
		return (0);
	printf("got there\n");
	if (!(map[0]))
		return (0);
	printf("got there\n");
	if (map_items_check(map) == 0)
		return (0);
	printf("got there\n");
	if (map_rectangle_check(map) == 0)
		return (0);
	printf("got there\n");
	if (map_walls_check(map) == 0)
		return (0);
	printf("got there\n");
	if (map_char_check(map) == 0)
		return (0);
	printf("got there\n");
	//floodfill
	return (1);
}

int	map_char_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (is_char_correct(map[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	is_char_correct(char c)
{
	if (c == '1')
		return (1);
	if (c == 'P')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'C')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}
int	map_items_check(char **map)
{
	int	items[3];
	int	i;
	int	j;

	i = 0;
	items[0] = 0;
	items[1] = 0;
	items[2] = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			process_char(map[i][j], items);
			j++;
		}
		i++;
	}
	if (items[0] >= 1 && items[1] == 1 && items[2] == 1)
		return (1);
	return (0);
}

void	process_char(char c, int items[3])
{
	if (c == 'C')
		(items[0])++;
	else if (c == 'E')
		(items[1])++;
	else if (c == 'P')
		(items[2])++;
	return ;
}
int	map_rectangle_check(char **map)
{
	int	i;
	int	strlen;

	i = 0;
	strlen = ft_strlen(map[i]);
	while (map[i])
	{
		if (strlen != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
	
}

int	map_walls_check(char **map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (map[i][j])
		if (map[i][j++] != '1')
			return (0);
	j--;
	while (map[i])
		if (map[i++][j] != '1')
			return (0);
	i--;
	while (j >= 0)
		if (map[i][j--] != '1')
			return (0);
	j++;
	while (i >= 0)
		if (map[i--][j] != '1')
			return (0);
	return (1);
}
int	key_pressed(int keycode, t_game *game)
{
	char	*hero;
	char	*target;
	int		x;
	int		y;
	
	if (keycode == XK_Escape)
		exit_game_protocol(game);	
	if (is_move(keycode))
	{
		x = game->player_xy.x;
		y = game->player_xy.y;
		hero = &(game->map[y][x]);
		handle_move_key(keycode, &x, &y);
		target = &(game->map[y][x]);
		if ((*target) != '1')
		{
			if (swap_char(hero, target, game) == 1)
			{
				game->player_xy.x = x;
				game->player_xy.y = y;
				generate_map(game, game->mlx_win, game->mlx);
			}
		}
	}
	return (0);
}

void	handle_move_key(int keycode, int *x, int *y)
{
	if (keycode == XK_w || keycode == XK_W)
			(*y)--;
	else if (keycode == XK_s || keycode == XK_S)
		(*y)++;
	else if (keycode == XK_a || keycode == XK_A)
		(*x)--;
	else if (keycode == XK_d || keycode == XK_D)
		(*x)++;
	return ;
}
int	swap_char(char *hero, char *square, t_game *game)
{
	if (*square == 'E')
	{
		if (is_map_coinless(game->map))
			exit_game_protocol(game);
		else
			return(0);
	}
	(game->move_count)++;
	write(1, "move : ", 7);
	ft_putnbr_fd(game->move_count, 1);
	write(1, "\n", 1); // should be printf i for sure, also we protect write in this house
	*square = *hero;
	*hero = '0';
	
	return (1);
}

int	is_map_coinless(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	exit_game_protocol(t_game *game)
{
	if (game->coin)
		mlx_destroy_image (game->mlx, game->coin);
	if (game->wall)
		mlx_destroy_image (game->mlx, game->wall);
	if (game->hero)
		mlx_destroy_image (game->mlx, game->hero);
	if (game->exit)
		mlx_destroy_image (game->mlx, game->exit);
	if (game->floor)
		mlx_destroy_image (game->mlx, game->floor);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	ft_free_array((void **)game->map);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}


int	is_move(int keycode)
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
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			generate_square(game, mlx_win, mlx, x, y);
			x++;
		}
		y++;
	}
	return ;
}

void	generate_square(t_game *game, void *mlx_win, void *mlx,int x, int y)
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
}

void	init_all(t_game *game, char **argv)
{
	get_map_grid(argv, game);
	if (is_map_valid(game->map) == 0)
	{
		ft_free_array((void **)game->map);
		perror_and_exit("map is not valid");
	}
	game->move_count = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_free_array((void **)game->map);
		perror_and_exit("failed to connect to graphical system\n");
	}	
	game->wall = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &(game->img_width), &(game->img_height));
    //check if fail AND check if it exists before destroy
	game->coin = mlx_xpm_file_to_image(game->mlx, "./coin.xpm", &(game->img_width), &(game->img_height));
	game->floor = mlx_xpm_file_to_image(game->mlx, "./floor.xpm", &(game->img_width), &(game->img_height));
	game->hero = mlx_xpm_file_to_image(game->mlx, "./hero.xpm", &(game->img_width), &(game->img_height));
    game->exit = mlx_xpm_file_to_image(game->mlx, "./end.xpm", &(game->img_width), &(game->img_height));
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * game->img_width, game->map_height * game->img_height, "Hello world!"); // to define dynamically in initall
	if (!game->mlx_win)
		perror_and_exit("window failed to create"); // need to free stuff
}
void	init_images(t_game *game)
{
	game->wall = NULL;
	game->coin = NULL;
	game->floor = NULL;
	game->hero = NULL;
    game->exit = NULL;
	
	game->wall = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &(game->img_width), &(game->img_height));
	game->coin = mlx_xpm_file_to_image(game->mlx, "./coin.xpm", &(game->img_width), &(game->img_height));
	game->floor = mlx_xpm_file_to_image(game->mlx, "./floor.xpm", &(game->img_width), &(game->img_height));
	game->hero = mlx_xpm_file_to_image(game->mlx, "./hero.xpm", &(game->img_width), &(game->img_height));
    game->exit = mlx_xpm_file_to_image(game->mlx, "./end.xpm", &(game->img_width), &(game->img_height));
}

int	safe_xpm_to_img(t_game *game, xpm_to_img func)
{
	
}

void	get_map_grid(char **argv, t_game *game)
{
	char *map_array;
	
	map_array = get_map_array(argv[1], game); //this is safe
	game->map = ft_split(map_array, '\n');
	free(map_array);
	if (!game->map)
		perror_and_exit("split failed"); // should be all done and safe
	return ;
}

char	*get_map_array(char *mapname, t_game *game)
{
	int		mapfd;
	char	*new_line;
	char	*map;
	
	mapfd = open(mapname, O_RDONLY);
	if (mapfd == -1)
		perror_and_exit("failed to open map fd"); //need to update after i know how to mlx destroy;
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

char	*empty_malloc(void)
{
	char *empty_malloc;

	empty_malloc = malloc(sizeof(char));
	if (!empty_malloc)
		perror_and_exit("empty malloc failed");
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
