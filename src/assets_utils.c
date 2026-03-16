/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:45:46 by marccost          #+#    #+#             */
/*   Updated: 2026/03/13 16:46:16 by marccost         ###   ########.ch       */
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
		&& check_texture(assets->n_texture)
		&& check_texture(assets->s_texture)
		&& check_texture(assets->w_texture)
		&& check_texture(assets->e_texture));
}

void	free_assets(t_assets *assets)
{
	if (assets->ceiling_color)
		free(assets->ceiling_color);
	if (assets->floor_color)
		free(assets->floor_color);
	if (assets->n_texture)
		free(assets->n_texture);
	if (assets->s_texture)
		free(assets->s_texture);
	if (assets->e_texture)
		free(assets->e_texture);
	if (assets->w_texture)
		free(assets->w_texture);
}