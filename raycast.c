#include "cub3d.h"

void	compute_dist(t_data *game, t_ray *ray, t_hit *hit) // calcul de la distance
{
	if (ray->side == 0)
		hit->dist = (ray->mapX - game->player.posx
				+ (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		hit->dist = (ray->mapY - game->player.posy
				+ (1 - ray->stepY) / 2) / ray->rayDirY;
	hit->side = ray->side;
	hit->stepX = ray->stepX;
	hit->stepY = ray->stepY;
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
	hit.ray = ray;
	return (hit);
}  