
#include "cub3d.h"

int ft_tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}


int is_in_block(int x, int y, t_data *game)
{
    int tile_w;
    int tile_h;
    int row;
    int col;

    if (!game || !game->map.map)
        return (0);
    if (game->map.size_map[0] <= 0 || game->map.size_map[1] <= 0)
        return (0);
    tile_w = 1920 / game->map.size_map[0];
    tile_h = 1080 / game->map.size_map[1];
    if (tile_w == 0 || tile_h == 0)
        return (0);
    col = x / tile_w;
    row = y / tile_h;
    if (row < 0 || col < 0 || row >= game->map.size_map[1] || col >= game->map.size_map[0])
        return (0);
    if (game->map.map[row][col] == '1')
        return (1);
    return (0);
}