/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:19:34 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/11 16:54:01 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>


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
	char	**map_double;
	int		img_height;
	int		img_width;
	size_t	map_height;
	size_t	map_width;
	void	*mlx_win;
	void	*mlx;
	t_xy	player_xy;
	int		move_count;
}   t_game;

# define UP 	1
# define DOWN 	2
# define LEFT 	3
# define RIGHT 	4

///////////LIBFT/////////
void	ft_free_array(void **array);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_free_s1(char *s1, char const *s2);
void	ft_putnbr_fd(int n, int fd);
////////////////////////////

typedef void *(*xpm_to_img) (void *mlx, char *file, int *width, int *height);


#endif