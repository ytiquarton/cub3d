#include "cub3d.h"

#define NOLINE 40

void draw_one_wall(t_data *game, int height, int pos)
{
    int rel_posx;
    float rel_height;
    int rel_posy;
    int c_y;
    int c_x;

    rel_posx = (1920 / 40) * pos;
    rel_height = (1080 / 1920) * height;
    rel_height = 1080 - rel_height;
    rel_posy = (1080 - rel_height) / 2;
    c_x = 0;
    printf("height = %d, pos = %d\n", height, pos);
    while (c_x < 27)
    {
        c_y = 0;
        while (c_y < rel_height)
        {
            my_mlx_pixel_put(&game->windata, rel_posx + c_x, rel_posy + c_y, 0x00FF0000);
            c_y++;
        }
        c_x++;
    }
}

void draw_walls(t_data *game)
{
	int front_pix;
	float x;
	float y;
	float line;
	
	line = 0;
	while (line < NOLINE / 2) // côté gauche
	{
        // printf("debug2\n");
		front_pix = 0;
		x = game->player.posx;
		x += 4;
		y = game->player.posy;
		y += 4;
		while (front_pix < ROV)
		{
			if (is_in_block(x, y, game))
            {
				draw_one_wall(game, front_pix, line);
                break;
            }
			x += cos(game->player.angle + (line / 35.0f));
			y += sin(game->player.angle + (line / 35.0f));
			if (x > win_x || y > win_y || x < 0 || y < 0)
				break ;
			front_pix++;
		}
		line++;
	}
	while (line > 0) // coté droit ou jsp
	{
		front_pix = 0;
		x = game->player.posx;
		x += 4;
		y = game->player.posy;
		y += 4;
		while (front_pix < ROV)
		{
			if (is_in_block(x, y, game))
            {
				draw_one_wall(game, front_pix, line + 19);
                break;
            }
			x += cos(game->player.angle - (line / 35.0f));
			y += sin(game->player.angle - (line / 35.0f));
			if (x > win_x || y > win_y || x < 0 || y < 0)
				break ;
			front_pix++;
		}
		line--;
	}
}