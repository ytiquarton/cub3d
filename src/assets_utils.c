/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudet <mclaudet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:29:51 by marccost          #+#    #+#             */
/*   Updated: 2026/03/30 20:29:39 by mclaudet         ###   ########.fr       */
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
	if (assets->floor_color)
		free(assets->floor_color);
	if (assets->n_texture.addr)
		free(assets->n_texture.addr);
	if (assets->s_texture.addr)
		free(assets->s_texture.addr);
	if (assets->e_texture.addr)
		free(assets->e_texture.addr);
	if (assets->w_texture.addr)
		free(assets->w_texture.addr);
}
