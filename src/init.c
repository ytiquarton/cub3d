#include "cub3d.h"

int load_texture(t_data *game, t_texture *tex)
{
	tex->width = 960;
	tex->height = 600;
    tex->img = mlx_xpm_file_to_image(game->mlx.mlx, tex->addr, &tex->width, &tex->height);
	if (!tex->img)
	{
		printf("error while loading_textures");
		return (-1);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
	return (0);
}