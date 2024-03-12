/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:19:05 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/12 16:38:09 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	*empty_malloc(void);
void	perror_and_exit(char *error_message);
void	free_two_and_exit(void *tofree_1, void *tofree_2, char *error_message);
char	*get_map_array(char *mapname, t_game *game);

void	init_all(t_game *game, char **argv);
int		key_pressed(int keycode, t_game *game);
int		swap_char(char *hero, char *square, t_game *game);
int		is_move(int keycode);
void	get_map_grid(char **argv, t_game *game);
char	*get_map_array(char *mapname, t_game *game);

int		is_map_coinless(char **map);
void	handle_move_key(int keycode, int *x, int *y);
int		game_img_check(t_game *game);
void	init_images(t_game *game);
void	ber_check(char *str);
int		is_map_valid(t_game *game);
int		map_items_check(char **map);
void	process_char(char c, int items[3]);
void	cleanup(t_game *game);
void	bzero_struct(t_game *game);

static void	generate_square(t_game *game, void *mlx_win, void *mlx,int x, int y);

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

static void	generate_square(t_game *game, void *mlx_win, void *mlx,int x, int y)
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
		mlx_put_image_to_window(mlx, mlx_win, game->hero, game->img_width * x, game->img_height * y);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	    perror_and_exit("unvalid number of arguments\n");
	init_all(&game, argv);
	generate_map(&game, game.mlx_win, game.mlx);
	mlx_hook(game.mlx_win, KeyPress, KeyPressMask, key_pressed, (void *)&game);
	mlx_hook(game.mlx_win, DestroyNotify, StructureNotifyMask, exit_game_protocol, (void *)&game);
	mlx_loop(game.mlx);
}

void	init_all(t_game *game, char **argv)
{
	bzero_struct(game);
	get_map_grid(argv, game);
	get_P_xy(game);
	if (is_map_valid(game) == 0)
	{	
		game->error_message = "map is invalid";
		exit_game_protocol(game);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
	{	
		game->error_message = "failed to connect to server";
		exit_game_protocol(game);
	}
	init_images(game);
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * game->img_width, game->map_height * game->img_height, "Hello world!"); // to define dynamically in initall
	if (!game->mlx_win)
	{	
		game->error_message = "failed to generate window";
		exit_game_protocol(game);
	}
}
int	exit_game_protocol(t_game *game)
{
	cleanup(game);
	if (game->error_message)
		perror_and_exit(game->error_message);
	else
		exit(EXIT_SUCCESS);
}
void	cleanup(t_game *game)
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
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	ft_free_array((void **)game->map);
	ft_free_array((void **)game->map_double);
	free(game->mlx);
}


void	bzero_struct(t_game *game)
{
	game->wall = NULL;
	game->coin = NULL;
	game->floor = NULL;
	game->hero = NULL;
	game->exit = NULL;
	game->map = NULL;
	game->mlx_win = NULL;
	game->mlx = NULL;
	game->map_double = NULL;
	game->error_message = NULL;
	game->move_count = 0;
	return ;
}

void	init_images(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &(game->img_width), &(game->img_height));
	game->coin = mlx_xpm_file_to_image(game->mlx, "./coin.xpm", &(game->img_width), &(game->img_height));
	game->floor = mlx_xpm_file_to_image(game->mlx, "./floor.xpm", &(game->img_width), &(game->img_height));
	game->hero = mlx_xpm_file_to_image(game->mlx, "./hero.xpm", &(game->img_width), &(game->img_height));
    game->exit = mlx_xpm_file_to_image(game->mlx, "./end.xpm", &(game->img_width), &(game->img_height));
	if (game_img_check(game) == 0)
	{	
		perror("failed to load img");
		exit_game_protocol(game);
	}	
}
int	game_img_check(t_game *game)
{
	int err_status;

	err_status = 1;
	if (!(game->wall))
		err_status = 0;
	if (!(game->coin))
		err_status = 0;
	if (!(game->floor))
		err_status = 0;
	if (!(game->hero))
		err_status = 0;
	if (!(game->exit))
		err_status = 0;
	return (err_status);
}

void	perror_and_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}


