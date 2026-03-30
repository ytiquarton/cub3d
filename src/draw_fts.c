#include "cub3d.h"

#define FOV 1.04719755

int	draw_sky_g(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y / 2)
		{
			my_mlx_pixel_put(&game->windata, x, y, 0x000000FF);
			y++;
		}
		while (y < WIN_Y)
		{
			my_mlx_pixel_put(&game->windata, x, y, 0x0000FF00);
			y++;
		}
		x++;
	}
	return (0);
}

void	draw_walls(t_data *game)
{
	t_hit	vars;
	int		i;
	double	ray_angle;
	double	perp_dist;

	i = 0;
	while (i < NOLINE)
	{
		ray_angle = game->player.angle + ((double)i
				- (double)NOLINE / 2.0) / (double)NOLINE * FOV;
		vars = raycast(game, cos(ray_angle), sin(ray_angle));
		perp_dist = vars.dist * cos(ray_angle - game->player.angle);
		if (perp_dist <= 0.000001)
			perp_dist = 0.000001;
		vars.height = (int)((double)WIN_Y / perp_dist);
		if (vars.height < 0)
			vars.height = 0;
		if (vars.height > WIN_Y)
			vars.height = WIN_Y;
		draw_textured_wall(game, vars, i, vars.height);
		i++;
	}
}

void	my_mlx_pixel_put(t_windata *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	if (x >= WIN_X || y >= WIN_Y)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}
