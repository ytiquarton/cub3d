/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/01/1970 01:00:00 by marccost          #+#    #+#             */
/*   Updated: 05/03/2026 23:24:31 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl.h"
# define PI 3.14159265

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx_data;

typedef struct s_windata
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_windata;

typedef struct s_player
{
	float	posx;
	float	posy;
	float	angle;
}				t_player;

typedef struct s_map
{
	int		size_map[2];
	char	**map;
}				t_map;

typedef struct s_vector3
{
	int	x;
	int	y;
	int	z;
}			t_vector3;

typedef struct s_assets
{
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	t_vector3	*floor_color;
	t_vector3	*ceiling_color;
}				t_assets;

typedef struct s_data
{
	t_mlx_data	mlx;
	t_windata	windata;
	t_player	player;
	t_map		map;
	t_assets	assets;
}				t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

void	move_right(t_data *game);
void	move_rear(t_data *game);
void	move_left(t_data *game);
void	move_front(t_data *game);
void	vanish_player(t_data *game);
void	my_mlx_pixel_put(t_windata *data, int x, int y, int color);
int		draw_map(char *name, t_data *game);
void	update_map(t_data *game);




#endif
