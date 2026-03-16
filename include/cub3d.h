#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl.h"
# define pi 3.14159265
# define WIN_X 1920
# define WIN_Y 1080
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

typedef struct s_vector3
{
	int	x;
	int	y;
	int	z;
}			t_vector3;

typedef struct s_texture
{
	void *img;
	char *addr;
	int width;
	int height;
	int bpp;
	int line_len;
	int endian;
}   t_texture;

typedef struct s_assets
{
	t_texture	n_texture;
	t_texture	s_texture;
	t_texture	w_texture;
	t_texture	e_texture;
	t_vector3	*floor_color;
	t_vector3	*ceiling_color;
}				t_assets;

typedef struct s_ray //structure pour les rayons du dda
{
	double  rayDirX;
	double  rayDirY;
	double  sideDistX; // distance jusqu'a la prochaine case
	double  sideDistY;
	double  deltaDistX; // dist pour passer d'une case à la suivante
	double  deltaDistY;
	int     mapX; //position du rayon dans la map
	int     mapY;
	int     stepX; // direction du deplacement
	int     stepY;
	int     side; // mur vertical ou horizontal
}   t_ray;

typedef struct s_hit // structure pour les infos du mur touche
{
	double  dist; // distance joueur/mur
	double  wallX; // position sur le mur
	int     height; // hauteur du mur a dessiner
	int     side; // direction
	int     stepX;
	int     stepY;
	t_ray   ray; // ray information associated with this hit (filled by raycast)
}               t_hit;

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

void move_right(t_data *game);
void move_rear(t_data *game);
void move_left(t_data *game);
void move_front(t_data *game);
void vanish_player(t_data *game);
void my_mlx_pixel_put(t_windata *data, int x, int y, int color);
int	draw_map(char *name, t_data *game);
void update_map(t_data *game);
int is_in_block(int x, int y, t_data *game);
// void init_map(char *name, t_data *game);
void draw_walls(t_data *game);
float *intersect(t_data *game, float dx_dy[2]);


int		draw_sky_g(t_data *game);
int		load_texture(t_data *game, t_texture *tex);
void	draw_textured_wall(t_data *game, t_hit hit, int x, int lineHeight);

void	init_delta(t_ray *ray);
void	init_step_x(t_data *game, t_ray *ray);
void	init_step_y(t_data *game, t_ray *ray);
void	dda_step(t_ray *ray);
void	perform_dda(t_data *game, t_ray *ray);

void	compute_dist(t_data *game, t_ray *ray, t_hit *hit);
void	compute_wallx(t_data *game, t_ray *ray, t_hit *hit);
t_hit	raycast(t_data *game, double rayDirX, double rayDirY);

#endif
