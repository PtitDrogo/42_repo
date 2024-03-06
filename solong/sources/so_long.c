/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:19:05 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/06 16:51:44 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
#include "mlx_int.h"
#include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(int argc, char *argv[])
{
	printf("hi there\n");
	void	*mlx;
	void	*img;
	char	*relative_path = "./protagonist3.xpm";
	int		img_width;
	int		img_height;
	void	*mlx_win;

	// if (argc != 2)
	//     return (0);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	// mlx_put_image_to_window(mlx, mlx_win, img, img_width, img_height);
	// mlx_put_image_to_window(mlx, mlx_win, img, img_width + img_width, img_height);
	mlx_loop(mlx);
}

char	*magic(void	*img, char *mapname)
{
	int mapfd;
	
	mapfd = open(mapname, O_RDONLY);
	if (mapfd == -1)
		exit(EXIT_FAILURE);
	
	
	while ()
	{
		
	}
	 
}
