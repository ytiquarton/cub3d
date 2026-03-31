/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:13:07 by marccost          #+#    #+#             */
/*   Updated: 2026/03/31 14:13:11 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture(t_data *game, t_texture *tex)
{
	tex->width = 960;
	tex->height = 600;
	tex->img = mlx_xpm_file_to_image(game->mlx.mlx, tex->addr,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		printf("error while loading_textures");
		return (-1);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	return (0);
}
