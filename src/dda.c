#include "cub3d.h"


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
