#include "cub3d.h"

#define NOLINE WIN_X

void draw_one_wall(t_data *game, t_hit vars, int pos)
{
    int rel_posx;
	int rel_posy;
	int c_y;
	int c_x;
	int stripe_w;

	stripe_w = WIN_X / NOLINE;
	rel_posx = stripe_w * pos;
	rel_posy = (WIN_Y - vars.height) / 2;
	c_x = 0;
	while (c_x < stripe_w)
	{
		c_y = 0;
		while (c_y < vars.height)
		{
			my_mlx_pixel_put(&game->windata, rel_posx + c_x, rel_posy + c_y, 0x00FF0000);
			c_y++;
		}
		c_x++;
	}
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
		perpDist = vars.dist * cos(rayAngle - game->player.angle);
		if (perpDist <= 0.000001)
			perpDist = 0.000001;
		vars.height = (int)((double)WIN_Y / perpDist);
		if (vars.height < 0)
			vars.height = 0;
		if (vars.height > WIN_Y)
			vars.height = WIN_Y;
		draw_one_wall(game, vars, i);
		i++;
	}
	// debug: you can uncomment the next line for a single summary print
	printf("last vars.dist = %lf, vars.side = %d, vars.wallX = %lf\n", vars.dist, vars.side, vars.wallX);
}

