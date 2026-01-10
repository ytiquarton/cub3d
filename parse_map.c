#include "cub3d.h"

char **add_one_malloc(char **tab)
{
    char **copy;
    int i = 0;

    copy = malloc((ft_tablen(tab) + 2) * sizeof(char *));
    while (tab[i])
    {
        copy[i] = tab[i];
        i++;
    }
    copy[i] = NULL;
    free(tab);
    return copy;
}


void init_map(int fd, t_data *game)
{
    char *line;
    int y = 0;

    game->map.map = malloc(sizeof(char *));
    game->map.map[0] = NULL;

    while ((line = get_next_line(fd)))
    {
        game->map.map = add_one_malloc(game->map.map);
        game->map.map[y++] = line;
    }

    game->map.map[y] = NULL;

    game->map.size_map[1] = y;
    game->map.size_map[0] = ft_strlen(game->map.map[0]) - 1; // sans '\n'
}


void draw_block(int x, int y, int tile_w, int tile_h, t_data *game)
{
    int i = 0;
    int j;

    while (i < tile_w)
    {
        j = 0;
        while (j < tile_h)
        {
            my_mlx_pixel_put(&game->windata, x + i, y + j, 0x00FFFF00);
            j++;
        }
        i++;
    }
}



void draw_map(char *name, t_data *game)
{
    int fd;
    int i;
    int j;
    int tile_w;
    int tile_h;

    fd = open(name, O_RDONLY);
    if (fd < 0)
        return;
    init_map(fd, game);
    tile_w = 1920 / game->map.size_map[0];
    tile_h = 1080 / game->map.size_map[1];
    i = 0;
    while (i < game->map.size_map[1])
    {
        j = 0;
        while (j < game->map.size_map[0])
        {
            if (game->map.map[i][j] == '1')
                draw_block(j * tile_w, i * tile_h, tile_w, tile_h, game);

            if (game->map.map[i][j] == 'P')
            {
                game->player.posx = j * tile_w + tile_w / 2;
                game->player.posy = i * tile_h + tile_h / 2;
            }
            j++;
        }
        i++;
    }
}