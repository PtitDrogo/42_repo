/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:07:35 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/12 16:14:29 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_move_key(int keycode, int *x, int *y);
static int	swap_char(char *hero, char *square, t_game *game);
static int	is_map_coinless(char **map);
static int	is_move(int keycode);

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
static void	handle_move_key(int keycode, int *x, int *y)
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

static int	swap_char(char *hero, char *square, t_game *game)
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

static int	is_map_coinless(char **map)
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

static int	is_move(int keycode)
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