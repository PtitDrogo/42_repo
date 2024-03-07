/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:19:34 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/07 14:36:54 by tfreydie         ###   ########.fr       */
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

typedef struct	s_game 
{
    void    *wall;
    void    *coins;
    void    *floor;
    void    *hero;
    void    *exit;
	int     height;
    int     width;
    char    *map;
}   t_game;


#endif