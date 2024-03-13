/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:28:32 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/13 17:04:56 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_exit(char **map, int y, int x);
static int	check_floodfill(char **map);
static int	floodfill(char **map, int y, int x);

int	path_check(t_game *game)
{
	floodfill(game->map_double, game->player_xy.y, game->player_xy.x);
	return (check_floodfill(game->map_double));
}

static int	floodfill(char **map, int y, int x)
{
	if (map[y][x] == 'F' || map[y][x] == '1' || map[y][x] == 'E')
		return (0);
	else
		map[y][x] = 'F';
	floodfill(map, y, x + 1);
	floodfill(map, y, x - 1);
	floodfill(map, y + 1, x);
	floodfill(map, y - 1, x);
	return (1);
}

static int	check_floodfill(char **map)
{
	int	y;
	int	x;
	int	status;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'P')
				return (0);
			if (map[y][x] == 'E')
				status = check_exit(map, y, x);
			x++;
		}
		y++;
	}
	return (status);
}

static int	check_exit(char **map, int y, int x)
{
	if (map[y + 1] && map[y + 1][x] == 'F')
		return (1);
	if (y >= 1 && map[y - 1][x] == 'F')
		return (1);
	if (map[y][x + 1] == 'F')
		return (1);
	if (x >= 1 && map[y][x - 1] == 'F')
		return (1);
	return (0);
}
