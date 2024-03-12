/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:15:45 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/12 18:02:19 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	bzero_struct(t_game *game);
static void	get_P_xy(t_game *game);
static void	init_images(t_game *game);
static int	game_img_check(t_game *game);

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
static void	bzero_struct(t_game *game)
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

static void	get_P_xy(t_game *game)
{
	int y;
	int x;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_xy.x = x;
				game->player_xy.y = y;
			}
			x++;
		}
		y++;
	}
	return ;
}

static void	init_images(t_game *game)
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
static int	game_img_check(t_game *game)
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

