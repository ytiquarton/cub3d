#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl.h"
# define pi 3.14159265
# define win_x 1920
# define win_y 1080
# define ROV 1000

typedef struct s_mlx_data
{
	void *mlx;
	void *mlx_win;
}              t_mlx_data;

typedef struct s_windata
{
	void *img;
	char *addr;
	int     bpp;
	int     line_length;
	int     endian;
}               t_windata;

typedef struct s_player
{
	float posx;
	float posy;
	float angle;
}               t_player;

typedef struct s_map
{
	int size_map[2];
	char **map;
}               t_map;

typedef struct s_data
{
	t_mlx_data	mlx;
	t_windata	windata;
	t_player	player;
	t_map       map;

}               t_data;

void move_right(t_data *game);
void move_rear(t_data *game);
void move_left(t_data *game);
void move_front(t_data *game);
void vanish_player(t_data *game);
void my_mlx_pixel_put(t_windata *data, int x, int y, int color);
void draw_map(char *name, t_data *game);
void update_map(t_data *game);
int is_in_block(int x, int y, t_data *game);
void init_map(char *name, t_data *game);
void draw_walls(t_data *game);

int draw_sky_g(t_data *game);




#endif
