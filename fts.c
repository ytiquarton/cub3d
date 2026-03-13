#include "cub3d.h"

#define NOLINE WIN_X

void draw_one_wall(t_data *game, int height, int pos)
{
    int rel_posx;
	int rel_posy;
	int c_y;
	int c_x;
	int stripe_w;

	stripe_w = WIN_X / NOLINE;
	rel_posx = stripe_w * pos;
	rel_posy = (WIN_Y - height) / 2;
	c_x = 0;
	while (c_x < stripe_w)
	{
		c_y = 0;
		while (c_y < height)
		{
			my_mlx_pixel_put(&game->windata, rel_posx + c_x, rel_posy + c_y, 0x00FF0000);
			c_y++;
		}
		c_x++;
	}
}

// // void draw_walls(t_data *game)
// // {
// // 	int front_pix;
// // 	float x;
// // 	float y;
// // 	float line;
	
// // 	line = 20;
// // 	while (line > 0) // côté gauche
// // 	{
// // 		front_pix = 0;
// // 		x = game->player.posx;
// // 		x += 4;
// // 		y = game->player.posy;
// // 		y += 4;
// // 		while (front_pix < ROV)
// // 		{
// // 			if (is_in_block(x, y, game))
// //             {
// // 				draw_one_wall(game, front_pix, (int)20 - line);
// //                 break;
// //             }
// // 			x += cos(game->player.angle + (line / 35.0f));
// // 			y += sin(game->player.angle + (line / 35.0f));
// // 			if (x > WIN_X || y > WIN_Y || x < 0 || y < 0)
// // 				break ;
// // 			front_pix++;
// // 		}
// // 		line--;
// // 	}
// // 	line = 0;
// // 	while (line < NOLINE / 2) // coté droit ou jsp
// // 	{
// // 		front_pix = 0;
// // 		x = game->player.posx;
// // 		x += 4;
// // 		y = game->player.posy;
// // 		y += 4;
// // 		while (front_pix < ROV)
// // 		{
// // 			if (is_in_block(x, y, game))
// //             {
// // 				draw_one_wall(game, front_pix, line + 19);
// //                 break;
// //             }
// // 			x += cos(game->player.angle - (line / 35.0f));
// // 			y += sin(game->player.angle - (line / 35.0f));
// // 			if (x > WIN_X || y > WIN_Y || x < 0 || y < 0)
// // 				break ;
// // 			front_pix++;
// // 		}
// // 		line++;
// // 	}
// // }

// void check_orientation_x(t_data *game, float *pos_inter)
// {
// 	if ((pos_inter[1] - game->player.posy) > 0)
// 		pos_inter[2] = 0; //NORD
// 	else
// 		pos_inter[2] = 1; //SUD
// }

// void check_orientation_y(t_data *game, float *pos_inter)
// {
// 	if ((pos_inter[0] - game->player.posx) > 0)
// 		pos_inter[2] = 3; //OUEST
// 	else
// 		pos_inter[2] = 2; //EST

// }

// int check_nearest(t_data *game, float *pos_inter, float x, float y)
// {
// 	if (fabs((pos_inter[0] - game->player.posx) + (pos_inter[1] - game->player.posy)) < fabs((x - game->player.posx) + (y - game->player.posy)))
// 		return (1);
// 	else
// 	{
// 		pos_inter[0] = x;
// 		pos_inter[1] = y;
// 		check_orientation_y(game, pos_inter);
// 		return (2);
// 	}
// }

// int check_if_intersect(t_data *game, float px, float py)
// {
// 	int row;
// 	int col;

// 	if (!game || !game->map.map)
// 		return (0);
// 	col = (int)px;
// 	row = (int) py;
// 	if (row < 0 || col < 0 || row >= game->map.size_map[1] || col >= game->map.size_map[0])
// 		return (0);
// 	//printf("col = %d, row = %d, px = %f, py = %f\n", col, row, px, py);
// 	if (game->map.map[row][col] == '1')
// 		return (1);
// 	return (0);
// }

// // faire la fonction pour voir lintersection plus rapidement avec calcul des droites (voir dessins)

// float* intersect_x(t_data *game, float slope, float shift, float *pos_inter)
// {
// 	float y;
// 	float x;

// 	x = 0;
// 	// printf("slope = %f, shift = %f\n", slope, shift);
// 	y = (slope * x) + shift;
// 	while (check_if_intersect(game, x, y) != 1)
// 	{
// 		x += 1.0f;
// 		y = (slope * x) + shift;
// 		if (x < 0 || x >= game->map.size_map[0] || y < 0 || y >= game->map.size_map[1])
// 			return (NULL);
// 	}
// 	pos_inter[0] = x;
// 	pos_inter[1] = y;
// 	check_orientation_x(game, pos_inter);
// 	return (pos_inter);
	
// }

// float* intersect_x_vert(t_data *game, float *pos_inter)
// {
// 	float y;
// 	float x;

// 	x = 0;
// 	y = game->player.posy;
// 	printf("gameposy = %f\n", y);
// 	while (check_if_intersect(game, x, y) != 1)
// 	{
// 		x += 1.0f;
// 		if (x < 0 || x >= ((float) game->map.size_map[0]))
// 			return (NULL);
// 		if (x >= game->map.size_map[0])
// 			return (NULL);
// 	}
// 	pos_inter[0] = x;
// 	pos_inter[1] = y;
// 	check_orientation_x(game, pos_inter);
// 	return (pos_inter);
	
// }

// float* intersect_y(t_data *game, float slope, float shift, float *pos_inter)
// {
// 	float x;
// 	float y;

	
// 	y = 0;
// 	x = (y - shift) / slope;
// 	while (check_if_intersect(game, x, y) != 1)
// 	{
// 		y += 1.0f;
// 		x = (y - shift) / slope;
// 		if (y < 0  || x < 0 || x >= game->map.size_map[0] || y >= game->map.size_map[1])
// 			return (NULL);
// 	}
// 	check_nearest(game, pos_inter, x, y);// si 1 = intersectx est plus proche si 2 = intersect y
// 	return (pos_inter);
// }

// float *intersect(t_data *game, float dx_dy[2])
// {
// 	float *pos_inter; // [0] = x, [1] = y, [2] = face du mur (nord sudt est ouest) 0 = nord 1 = sud 2 = est 3 = ouest
// 	float slope;
// 	float shift;

// 	pos_inter = malloc (3 * sizeof(float)); // SECURISER LE MALLOC
// 	if (!pos_inter)
// 		return (NULL);
// 	if (dx_dy[1] == 0)
// 	{
// 		if (intersect_x_vert(game, pos_inter) == NULL)
// 		{
// 			free(pos_inter);
// 			return (NULL);
// 		}
// 		return (pos_inter);
// 	}
// 	slope = dx_dy[1] / dx_dy[0];
// 	shift = game->player.posy - (slope * (game->player.posx));
// 	if (intersect_x(game, slope, shift, pos_inter) == NULL)
// 	{
// 		free(pos_inter);
// 		return (NULL);
// 	}
// 	if (intersect_y(game, slope, shift, pos_inter) == NULL)
// 	{
// 		free(pos_inter);
// 		return (NULL);
// 	}
// 	return (pos_inter);
// }

// float calc_pythagore(float a, float b)
// {
// 	float c;

// 	c = sqrt(a * a + b * b);
// 	return (c);
// }

// float calc_distance(t_data *game, float dx_dy[2])
// {
// 	float *pos_inter;
// 	float dist;

// 	pos_inter = intersect(game, dx_dy);
// 	if (!pos_inter)
// 	{
// 		printf("pas d'inter\n");
// 		return (0.0f);
// 	}
// 	printf("pos_inter[0] = %f, pos_inter[1] = %f\n", pos_inter[0], pos_inter[1]);
// 	dist = calc_pythagore(fabs(pos_inter[0] - game->player.posx), fabs(pos_inter[1] - game->player.posy));
// 	free(pos_inter);
// 	printf ("dist = %f\n", dist);
// 	return (dist);
// }

// void draw_walls(t_data *game)
// {
// 	int line;
// 	float dx_dy[2];

// 	line = 0;
// 	while (line < NOLINE)
// 	{
// 		dx_dy[0] = cos(game->player.angle + (line / 35.0f));
// 		dx_dy[1] = sin(game->player.angle + (line / 35.0f));
// 		printf("dx_dy = %f, %f\n", dx_dy[0], dx_dy[1]);
// 		draw_one_wall(game, calc_distance(game, dx_dy), line);
// 		line++;
// 	}
// }

// /*

// fonction pour trouver x : (y - b) / a = x

// fonction pour trouver y : ax + b = y (forme canonique)

// fonction pour trouver décalage :  b = y - ax

// fonction pour trouver pente : a = dy/dx

// */


typedef struct s_ray
{
	double	rayDirX;
	double	rayDirY;
	double	sideDistX; // distance jusqu'a la prochaine case
	double	sideDistY;
	double	deltaDistX; // dist pour passer d'une case à la suivante
	double	deltaDistY;
	int		mapX; //position du rayon dans la map
	int		mapY;
	int		stepX; // direction du deplacement
	int		stepY;
	int		side; // mur vertical ou horizontal
}	t_ray;

typedef struct s_hit
{
	double	dist; // distance joueur/mur
	double	wallX; // position sur le mur
	int		side; // direction
}	t_hit;

void	init_map_pos(t_data *game, t_ray *ray) // initier la position dans la map
{
	ray->mapX = (int)game->player.posx;
	ray->mapY = (int)game->player.posy;
}

void	init_delta(t_ray *ray) // calcul delta de la distance (entre ligne de grille)
{
	/* protect against zero ray direction components */
	if (ray->rayDirX == 0)
		ray->deltaDistX = 1e30;
	else
		ray->deltaDistX = fabs(1 / ray->rayDirX);
	if (ray->rayDirY == 0)
		ray->deltaDistY = 1e30;
	else
		ray->deltaDistY = fabs(1 / ray->rayDirY);
}

void	init_step_x(t_data *game, t_ray *ray) //initialisation de stepx 
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (game->player.posx - ray->mapX)
			* ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - game->player.posx)
			* ray->deltaDistX;
	}
}

void	init_step_y(t_data *game, t_ray *ray) // initialisation de step y
{
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (game->player.posy - ray->mapY)
			* ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - game->player.posy)
			* ray->deltaDistY;
	}
}

void	dda_step(t_ray *ray) // avancer d'une case dans la grille 
{
	if (ray->sideDistX < ray->sideDistY) // si touche vertical avant
	{
		ray->sideDistX += ray->deltaDistX;
		ray->mapX += ray->stepX;
		ray->side = 0;
	}
	else
	{
		ray->sideDistY += ray->deltaDistY;
		ray->mapY += ray->stepY;
		ray->side = 1;
	}
}

void	perform_dda(t_data *game, t_ray *ray) // boucle dda
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		dda_step(ray);
		/* guard against stepping outside the map bounds */
		if (!game || !game->map.map || ray->mapX < 0 || ray->mapY < 0
			|| ray->mapX >= game->map.size_map[0]
			|| ray->mapY >= game->map.size_map[1])
		{
			/* treat out-of-bounds as a hit to stop the loop */
			hit = 1;
			break;
		}
		if (game->map.map[ray->mapY][ray->mapX] == '1')
			hit = 1;
	}
}

void	compute_dist(t_data *game, t_ray *ray, t_hit *hit) // calcul de la distance
{
	if (ray->side == 0)
		hit->dist = (ray->mapX - game->player.posx
				+ (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		hit->dist = (ray->mapY - game->player.posy
				+ (1 - ray->stepY) / 2) / ray->rayDirY;
	hit->side = ray->side;
}

void	compute_wallx(t_data *game, t_ray *ray, t_hit *hit) // calcul de la position texture 
{
	double	wallX;

	if (ray->side == 0)
		wallX = game->player.posy + hit->dist * ray->rayDirY;
	else
		wallX = game->player.posx + hit->dist * ray->rayDirX;
	hit->wallX = wallX - floor(wallX);
}

t_hit	raycast(t_data *game, double rayDirX, double rayDirY)
{
	t_ray	ray;
	t_hit	hit;

	ray.rayDirX = rayDirX;
	ray.rayDirY = rayDirY;
	ray.mapX = (int)game->player.posx;
	ray.mapY = (int) game->player.posy;
	init_delta(&ray);
	init_step_x(game, &ray);
	init_step_y(game, &ray);
	perform_dda(game, &ray);
	compute_dist(game, &ray, &hit);
	compute_wallx(game, &ray, &hit);
	return (hit);
}

void draw_walls(t_data *game)
{
	t_hit	vars;
	double rayDirX;
	double rayDirY;
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
		rayDirX = cos(rayAngle);
		rayDirY = sin(rayAngle);
		vars = raycast(game, rayDirX, rayDirY);
		/* correct distance for fish-eye by using perpendicular distance */
		double perpDist = vars.dist * cos(rayAngle - game->player.angle);
		if (perpDist <= 0.000001)
			perpDist = 0.000001;
		int lineHeight = (int)((double)WIN_Y / perpDist);
		if (lineHeight < 0)
			lineHeight = 0;
		if (lineHeight > WIN_Y)
			lineHeight = WIN_Y;
		draw_one_wall(game, lineHeight, i);
		i++;
	}
	// debug: you can uncomment the next line for a single summary print
	printf("last vars.dist = %lf, vars.side = %d, vars.wallX = %lf\n", vars.dist, vars.side, vars.wallX);
}

