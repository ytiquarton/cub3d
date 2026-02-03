#include "cub3d.h"

#define NOLINE 40

void draw_one_wall(t_data *game, int height, int pos)
{
    int rel_posx;
    float rel_height;
    int rel_posy;
    int c_y;
    int c_x;

    rel_posx = (1920 / NOLINE) * pos;
    rel_height = (1080.0f / 1920.0f) * (float) height; // largeur de l'ecran divise par la longueur max du fil + hauteur normalement du mur
    // rel_height = 1080 - rel_height;
    rel_posy = (1080 - (int) rel_height) / 2;
    c_x = 0;
    printf("height = %d, pos = %d, relposx = %d, relheight = %f\n", height, pos, rel_posx, rel_height);
    while (c_x < 1920 / NOLINE)
    {
        c_y = 0;
        while (c_y < (int) rel_height)
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
	
	line = 20;
	while (line > 0) // côté gauche
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
				draw_one_wall(game, front_pix, (int)20 - line);
                break;
            }
			x += cos(game->player.angle + (line / 35.0f));
			y += sin(game->player.angle + (line / 35.0f));
			if (x > WIN_X || y > WIN_Y || x < 0 || y < 0)
				break ;
			front_pix++;
		}
		line--;
	}
	line = 0;
	while (line < NOLINE / 2) // coté droit ou jsp
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
			if (x > WIN_X || y > WIN_Y || x < 0 || y < 0)
				break ;
			front_pix++;
		}
		line++;
	}
}

// faire la fonction pour voir lintersection plus rapidement avec calcul des droites (voir dessins)

int intersect_x(t_data *game, float slope, float shift)
{
	
}

int intersect_y(t_data *game, float slope, float shift)
{
	float x;

	while ()
}

int check_if_intersect(t_data *game, float pos[2])
{
	
}

int *intersect(t_data *game, float dx_dy[2])
{
	int pos_int[2];
	float slope;
	float shift;

	slope = dx_dy[0] / dx_dy[1];
	shift = -1 * (slope * game->player.posx - game->player.posy);
	
}
