/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:47:09 by marccost          #+#    #+#             */
/*   Updated: 2026/03/31 16:47:16 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	in_range(int min, int max, int x)
{
	return (x >= min && x <= max);
}

int	check_color(t_vector3 *vector)
{
	return (vector
		&& in_range(0, 255, vector->x)
		&& in_range(0, 255, vector->y)
		&& in_range(0, 255, vector->z));
}

int	check_texture(char *texture)
{
	return (texture && !access(texture, R_OK));
}

int	check_loaded_assets(t_assets *assets)
{
	return (check_color(assets->ceiling_color)
		&& check_color(assets->floor_color)
		&& check_texture(assets->n_texture.addr)
		&& check_texture(assets->s_texture.addr)
		&& check_texture(assets->w_texture.addr)
		&& check_texture(assets->e_texture.addr));
}

void	free_assets(t_assets *assets)
{
	if (assets->ceiling_color)
		free(assets->ceiling_color);
	assets->ceiling_color = 0;
	if (assets->floor_color)
		free(assets->floor_color);
	assets->floor_color = 0;
	if (assets->n_texture.addr)
		free(assets->n_texture.addr);
	assets->n_texture.addr = 0;
	if (assets->s_texture.addr)
		free(assets->s_texture.addr);
	assets->s_texture.addr = 0;
	if (assets->e_texture.addr)
		free(assets->e_texture.addr);
	assets->e_texture.addr = 0;
	if (assets->w_texture.addr)
		free(assets->w_texture.addr);
	assets->w_texture.addr = 0;
}
