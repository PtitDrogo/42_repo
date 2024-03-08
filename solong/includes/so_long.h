/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:19:34 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/08 18:36:07 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"


typedef struct s_xy
{
	int	x;
	int	y;
} t_xy;

typedef struct	s_game 
{
	void	*wall;
	void	*coin;
	void	*floor;
	void	*hero;
	void	*exit;
	char	**map;
	int		img_height;
	int		img_width;
	int		map_height;
	int		map_width;
	void	*mlx_win;
	void	*mlx;
	t_xy	player_xy;
}   t_game;

# define UP 	1
# define DOWN 	2
# define LEFT 	3
# define RIGHT 	4
#endif