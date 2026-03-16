#include "cub3d.h"

int get_texture_pixel(t_texture *tex, int x, int y)
{
	char *dst;

	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

t_texture *select_texture(t_data *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->stepX > 0)
			return (&game->assets.w_texture);
		else
			return (&game->assets.e_texture);
	}
	else
	{
		if (ray->stepY > 0)
			return (&game->assets.n_texture);
		else
			return (&game->assets.s_texture);
	}
}

void draw_textured_wall(t_data *game, t_hit hit, int x, int lineHeight)
{
	t_texture *tex;
	int drawStart;
	int drawEnd;
	int texX;
	int texY;
	double step;
	double texPos;
	int y;

	tex = select_texture(game, &hit.ray);
	drawStart = -lineHeight / 2 + WIN_Y / 2;
	drawEnd = lineHeight / 2 + WIN_Y / 2;
	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= WIN_Y)
		drawEnd = WIN_Y - 1;

	texX = (int)(hit.wallX * tex->width);
	step = 1.0 * tex->height / lineHeight;
	texPos = (drawStart - WIN_Y / 2 + lineHeight / 2) * step;
	y = drawStart;
	while (y < drawEnd)
	{
		texY = (int) texPos;
		texPos += step;
		my_mlx_pixel_put(&game->windata, x, y, get_texture_pixel(tex, texX, texY));
		y++;
	}

}