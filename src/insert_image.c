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

int	get_texture_pixel(t_texture *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

t_texture	*select_texture(t_data *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (&game->assets.w_texture);
		else
			return (&game->assets.e_texture);
	}
	else
	{
		if (ray->step_y > 0)
			return (&game->assets.n_texture);
		else
			return (&game->assets.s_texture);
	}
}

void	draw_textured_wall(t_data *game, t_hit hit, int x, int line_height)
{
	t_texture		*tex;
	t_draw_tex_w	vars;

	tex = select_texture(game, &hit.ray);
	vars.draw_start = -line_height / 2 + WIN_Y / 2;
	vars.draw_end = line_height / 2 + WIN_Y / 2;
	if (vars.draw_start < 0)
		vars.draw_start = 0;
	if (vars.draw_end >= WIN_Y)
		vars.draw_end = WIN_Y - 1;
	vars.tex_x = (int)(hit.wall_x * tex->width);
	if (tex == &game->assets.n_texture || tex == &game->assets.e_texture)
		vars.tex_x = tex->width - vars.tex_x - 1;
	vars.step = 1.0 * tex->height / line_height;
	vars.tex_pos = (vars.draw_start - WIN_Y / 2 + line_height / 2) * vars.step;
	vars.y = vars.draw_start;
	while (vars.y < vars.draw_end)
	{
		vars.tex_y = (int) vars.tex_pos;
		vars.tex_pos += vars.step;
		my_mlx_pixel_put(&game->windata, x, vars.y,
			get_texture_pixel(tex, vars.tex_x, vars.tex_y));
		vars.y++;
	}
}
