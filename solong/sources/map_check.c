/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:26:01 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/12 15:48:00 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_rectangle_check(char **map);
static int	map_walls_check(char **map);
static int	map_char_check(char **map);
static int	map_items_check(char **map);

int	is_map_valid(t_game *game)
{
	if (!(game->map))
		return (0);
	if (!(game->map[0]))
		return (0);
	if (map_items_check(game->map) == 0)
		return (0);
	if (map_rectangle_check(game->map) == 0)
		return (0);
	if (map_walls_check(game->map) == 0)
		return (0);
	if (map_char_check(game->map) == 0)
		return (0);
	if (path_check(game) == 0)
		return (0);
	return (1);
}
static int	map_rectangle_check(char **map)
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

static int	map_walls_check(char **map)
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

static int	map_char_check(char **map)
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

static int	map_items_check(char **map)
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
