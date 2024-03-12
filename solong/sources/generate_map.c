/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:34:36 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/12 18:08:58 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	generate_square(t_game *game, void *mlx_win, void *mlx, int x, int y);

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

static void	generate_square(t_game *game, void *mlx_win, void *mlx, int x, int y)
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