/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:19:34 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/12 16:27:47 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include "mlx_int.h"




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
	char	*error_message;
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

//////MAP//////
int	path_check(t_game *game);
int	is_map_valid(t_game *game);


/////utils/////
int		is_char_correct(char c);
void	process_char(char c, int items[3]);
void	get_P_xy(t_game *game);

///exit///
void	perror_and_exit(char *error_message);
int		exit_game_protocol(t_game *game);
void	cleanup(t_game *game);

//MAPGEN//
void	get_map_grid(char **argv, t_game *game);
void	generate_map(t_game *game, void *mlx_win, void *mlx);

#endif