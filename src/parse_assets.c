/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:55:48 by marccost          #+#    #+#             */
/*   Updated: 2026/03/08 21:55:48 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "map_utils.h"
#include "utils.h"
#include "assets_utils.h"

t_vector3	*parse_vector3(char *str)
{
	char		**strs;
	t_vector3	*output;

	strs = ft_split(str, ',');
	if (!strs)
		return (0);
	if (strs_len(strs) != 3)
		return (free_strs(strs), (t_vector3 *)0);
	output = malloc(sizeof(t_vector3));
	if (!output)
		return (free_strs(strs), (t_vector3 *)0);
	if (!is_valid_num(strs[0]) || !is_valid_num(strs[1])
		|| !is_valid_num(strs[2]))
		return (free_strs(strs), free(output), (t_vector3 *)0);
	output->x = ft_atoi(strs[0]);
	output->y = ft_atoi(strs[1]);
	output->z = ft_atoi(strs[2]);
	free_strs(strs);
	return (output);
}

int	load_asset_key_value_pair(char **key_value, t_assets *assets)
{
	if (!ft_strncmp("NO", key_value[0], 3))
		assets->n_texture = key_value[1];
	else if (!ft_strncmp("SO", key_value[0], 3))
		assets->s_texture = key_value[1];
	else if (!ft_strncmp("WE", key_value[0], 3))
		assets->w_texture = key_value[1];
	else if (!ft_strncmp("EA", key_value[0], 3))
		assets->e_texture = key_value[1];
	else if (!ft_strncmp("F", key_value[0], 2))
		assets->floor_color = parse_vector3(key_value[1]);
	else if (!ft_strncmp("C", key_value[0], 2))
		assets->ceiling_color = parse_vector3(key_value[1]);
	else
		return (0);
	return (1);
}

int	load_asset(char *line, t_assets *assets)
{
	char	**asset_key_value_pair;

	asset_key_value_pair = ft_split(line, ' ');
	if (!asset_key_value_pair)
		return (0);
	if (ft_strslen(asset_key_value_pair) != 2)
		return (free_strs(asset_key_value_pair), 0);
	if (!load_asset_key_value_pair(asset_key_value_pair, assets))
		return (free_strs(asset_key_value_pair), 0);
	free_strs(asset_key_value_pair);
	return (1);
}

int	is_empty_line(char *line)
{
	return (ft_strncmp("\n", line, 2));
}

char	**parse_assets(char	**lines, t_assets *assets)
{
	if (!lines)
		return (0);
	while (*lines)
	{
		if (!is_empty_line(*lines) && !load_asset(*lines, assets))
			break ;
		lines++;
	}
	if (!check_loaded_assets(assets))
		return (free_assets(assets), (char **)0);
	return (lines);
}
