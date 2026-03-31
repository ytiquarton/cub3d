/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:40:20 by marccost          #+#    #+#             */
/*   Updated: 2026/03/31 17:40:34 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	convert_colors(t_data *game)
{
	game->assets.f_col = ((game->assets.floor_color->x) << 16)
		+ ((game->assets.floor_color->y) << 8)
		+ ((game->assets.floor_color->z) << 0);
	game->assets.c_col = ((game->assets.ceiling_color->x) << 16)
		+ ((game->assets.ceiling_color->y) << 8)
		+ ((game->assets.ceiling_color->z) << 0);
	free(game->assets.floor_color);
	free(game->assets.ceiling_color);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	is_in_block(int x, int y, t_data *game)
{
	int	tile_w;
	int	tile_h;
	int	row;
	int	col;

	if (!game || !game->map.map)
		return (0);
	if (game->map.size_map[0] <= 0 || game->map.size_map[1] <= 0)
		return (0);
	tile_w = 1920 / game->map.size_map[0];
	tile_h = 1080 / game->map.size_map[1];
	if (tile_w == 0 || tile_h == 0)
		return (0);
	col = x / tile_w;
	row = y / tile_h;
	if (row < 0 || col < 0 || row >= game->map.size_map[1]
		|| col >= game->map.size_map[0])
		return (0);
	if (game->map.map[row][col] == '1')
		return (1);
	return (0);
}

int	is_valid_num(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
		index++;
	if (!str[index])
		return (0);
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}
