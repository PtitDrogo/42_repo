/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:34:36 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/13 15:37:55 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	generate_square(t_game *game, int x, int y);

void	generate_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			generate_square(game, x, y);
			x++;
		}
		y++;
	}
	return ;
}

static void	generate_square(t_game *game, int x, int y)
{
	void	*mlx;
	void	*mlx_win;
	int		img_x;
	int		img_y;

	img_x = game->img_width * x;
	img_y = game->img_width * y;
	mlx = game->mlx;
	mlx_win = game->mlx_win;
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(mlx, mlx_win, game->wall, img_x, img_y);
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(mlx, mlx_win, game->floor, img_x, img_y);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(mlx, mlx_win, game->coin, img_x, img_y);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(mlx, mlx_win, game->exit, img_x, img_y);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(mlx, mlx_win, game->hero, img_x, img_y);
}
