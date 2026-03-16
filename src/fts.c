#include "cub3d.h"

#define NOLINE WIN_X

// void draw_one_wall(t_data *game, t_hit vars, int pos)
// {
//     int rel_posx;
// 	int rel_posy;
// 	int c_y;
// 	int c_x;
// 	int stripe_w;

// 	stripe_w = WIN_X / NOLINE;
// 	rel_posx = stripe_w * pos;
// 	rel_posy = (WIN_Y - vars.height) / 2;
// 	c_x = 0;
// 	while (c_x < stripe_w)
// 	{
// 		c_y = 0;
// 		while (c_y < vars.height)
// 		{
// 			my_mlx_pixel_put(&game->windata, rel_posx + c_x, rel_posy + c_y, 0x00FF0000);
// 			c_y++;
// 		}
// 		c_x++;
// 	}
// }

void draw_walls(t_data *game)
{
	t_hit	vars;
	int i;
	double fov = pi / 3.0; /* 60 degrees */
	double camera_offset;
	double rayAngle;
	double perpDist;

	i = 0;
	while (i < NOLINE)
	{
		/* compute a ray per column by offsetting the player's angle */
		camera_offset = ((double)i - (double)NOLINE / 2.0) / (double)NOLINE; /* roughly -0.5..+0.5 */
		rayAngle = game->player.angle + camera_offset * fov;
		vars = raycast(game, cos(rayAngle), sin(rayAngle)); // raydirx et raydiry
		/* correct distance for fish-eye by using perpendicular distance */
		perpDist = vars.dist * cos(rayAngle - game->player.angle);
		if (perpDist <= 0.000001)
			perpDist = 0.000001;
		vars.height = (int)((double)WIN_Y / perpDist);
		if (vars.height < 0)
			vars.height = 0;
		if (vars.height > WIN_Y)
			vars.height = WIN_Y;
		draw_textured_wall(game, vars, i, vars.height);
		i++;
	}
	// debug: you can uncomment the next line for a single summary print
	printf("last vars.dist = %lf, vars.side = %d, vars.wallX = %lf\n", vars.dist, vars.side, vars.wallX);
}

