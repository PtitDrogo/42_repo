/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:19:05 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/13 15:30:15 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		perror_and_exit("unvalid number of arguments");
	init_all(&game, argv);
	generate_map(&game);
	mlx_hook(game.mlx_win, KeyPress, KeyPressMask, key_pressed, (void *)&game);
	mlx_hook(game.mlx_win, DestroyNotify, 1L << 17, exit_game, (void *)&game);
	mlx_loop(game.mlx);
}
