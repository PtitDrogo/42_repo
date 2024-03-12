/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:54:02 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/12 18:08:09 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cleanup(t_game *game);

int	exit_game_protocol(t_game *game)
{
	cleanup(game);
	if (game->error_message)
		perror_and_exit(game->error_message);
	else
		exit(EXIT_SUCCESS);
}

static void	cleanup(t_game *game)
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
