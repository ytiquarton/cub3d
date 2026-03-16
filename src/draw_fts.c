#include "cub3d.h"


int draw_sky_g(t_data *game)
{
    int x;
    int y;

    x = 0;
    while (x < WIN_X)
    {
        y = 0;
        while (y < WIN_Y / 2) //sky
        {
            my_mlx_pixel_put(&game->windata, x, y, 0x000000FF);
            y++;
        }
        while (y < WIN_Y) //ground
        {
            my_mlx_pixel_put(&game->windata, x, y, 0x0000FF00);
            y++;
        }
        x++;
    }
    return(0);
}
