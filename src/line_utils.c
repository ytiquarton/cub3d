#include "cub3d.h"

void	update_map(t_data *game)
{
	int	rp_x;
	int	rp_y;

	rp_x = game->player.posx / (1920 / game->map.size_map[0]);
	rp_y = game->player.posy / (1080 / game->map.size_map[1]);
	if (game->map.map[rp_y][rp_x] != 'P')
		game->map.map[rp_y][rp_x] = 'P';
}
