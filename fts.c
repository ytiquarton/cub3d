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

void check_orientation_x(t_data *game, int *pos_inter)
{
	if ((pos_inter[1] - game->player.posy) > 0)
		pos_inter[2] = 0; //NORD
	pos_inter[2] = 1; //SUD
}

void check_orientation_y(t_data *game, int *pos_inter)
{
	if ((pos_inter[0] - game->player.posx) > 0)
		pos_inter[2] = 3; //OUEST
	pos_inter[2] = 2; //EST

}

int check_nearest(t_data *game, int *pos_inter, float x, float y)
{
	if (fabs((pos_inter[0] - game->player.posx) + (pos_inter[1] - game->player.posy)) < fabs((x - game->player.posx) + (y - game->player.posy)))
		return (1);
	else
	{
		pos_inter[0] = x;
		pos_inter[1] = y;
		check_orientation_y(game, pos_inter);
		return (2);
	}
}

int check_if_intersect(t_data *game, int x, float y)
{
	int int_y;

	int_y = (int) y;
	if (game->map.map[x][int_y] == 1)
	{
		return (1);
	}
	return (0);

}

// faire la fonction pour voir lintersection plus rapidement avec calcul des droites (voir dessins)

int *intersect_x(t_data *game, float slope, float shift, int *pos_inter)
{
	float y;
	float x;

	x = 0;
	y = (slope * x) + shift;
	while (check_if_intersect(game, x, y) != 1)
	{
		x++;
		y = (slope * x) + shift;
	}
	if (x == game->map.size_map[1] - 1)
		return (NULL);
	else
	{
		pos_inter[0] = x;
		pos_inter[1] = y;
		check_orientation_x(game, pos_inter);
		return (pos_inter);
	}
	
}

int* intersect_y(t_data *game, float slope, float shift, int *pos_inter)
{
	float x;
	float y;

	y = 0;
	x = (y - shift) / slope;
	while (check_if_intersect(game, x, y) != 1)
	{
		y++;
		x = (y - shift) / slope;
	}
	if (y == game->map.size_map[0] - 1)
		return (NULL);
	else
	{
		check_nearest(game, pos_inter, x, y);// si 1 = intersectx est plus proche si 2 = intersect y
		return (pos_inter);
	}
}

int *intersect(t_data *game, float dx_dy[2])
{
	int* pos_inter; // [0] = x, [1] = y, [2] = face du mur (nord sudt est ouest) 0 = nord 1 = sud 2 = est 3 = ouest
	float slope;
	float shift;

	pos_inter = malloc (3 * sizeof(int)); // SECURISER LE MALLOC
	if (!pos_inter)
		return (NULL);
	slope = dx_dy[0] / dx_dy[1];
	shift = game->player.posy -  (slope * game->player.posx);
	intersect_x(game, slope, shift, pos_inter);
	if (intersect_x(game, slope, shift, pos_inter) == NULL)
		return NULL;
	if (intersect_y(game, slope, shift, pos_inter) == NULL)
		return NULL;
	return (pos_inter);
}

/*

fonction pour trouver x : (y - b) / a = x

fonction pour trouver y : ax + b = y (forme canonique)

fonction pour trouver décalage :  b = y - ax

fonction pour trouver pente : a = dx/dy

*/
