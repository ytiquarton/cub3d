#include "cub3d.h"

void update_map(t_data *game)
{
    int rp_x;
    int rp_y;

    rp_x = game->player.posx / (1920 / game->map.size_map[0]);
    rp_y = game->player.posy / (1080 / game->map.size_map[1]);

    /* rp_x is a column derived from posx, rp_y is a row derived from posy.
       The map is stored as map[row][col], so swap the indices when indexing. */
    if (game->map.map[rp_y][rp_x] != 'P')
        game->map.map[rp_y][rp_x] = 'P';
    printf ("col = %d row = %d\n", rp_x, rp_y);
}
