/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 31/03/2026 14:09:39 by marccost          #+#    #+#             */
/*   Updated: 31/03/2026 17:41:04 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	compute_dist(t_data *game, t_ray *ray, t_hit *hit)
{
	if (ray->side == 0)
		hit->dist = (ray->map_x - game->player.posx
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		hit->dist = (ray->map_y - game->player.posy
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	hit->side = ray->side;
	hit->step_x = ray->step_x;
	hit->step_y = ray->step_y;
}

void	compute_wallx(t_data *game, t_ray *ray, t_hit *hit)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.posy + hit->dist * ray->ray_dir_y;
	else
		wall_x = game->player.posx + hit->dist * ray->ray_dir_x;
	hit->wall_x = wall_x - floor(wall_x);
}

t_hit	raycast(t_data *game, double ray_dir_x, double ray_dir_y)
{
	t_ray	ray;
	t_hit	hit;

	ray.ray_dir_x = ray_dir_x;
	ray.ray_dir_y = ray_dir_y;
	ray.map_x = (int)game->player.posx;
	ray.map_y = (int) game->player.posy;
	init_delta(&ray);
	init_step_x(game, &ray);
	init_step_y(game, &ray);
	perform_dda(game, &ray);
	compute_dist(game, &ray, &hit);
	compute_wallx(game, &ray, &hit);
	hit.ray = ray;
	return (hit);
}
