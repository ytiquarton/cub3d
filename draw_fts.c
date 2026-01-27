#include "cub3d.h"


int draw_sky_g(t_data *game)
{
    int x;
    int y;

    x = 0;
    while (x < win_x)
    {
        y = 0;
        while (y < win_y / 2) //sky
        {
            my_mlx_pixel_put(&game->windata, x, y, 0x000000FF);
            y++;
        }
        while (y < win_y) //ground
        {
            my_mlx_pixel_put(&game->windata, x, y, 0x0000FF00);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->windata.img, 0, 0);
    return(0);
}

int draw_wall(t_data *game)
{
}