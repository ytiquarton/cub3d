/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:46:27 by marccost          #+#    #+#             */
/*   Updated: 2026/03/16 13:46:37 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map_utils.h"
#include "map_check.h"
#include "libft.h"
#include "file_utils.h"
#include "parse_assets.h"
#include "utils.h"

char	**add_one_malloc(char **tab)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc((ft_strslen(tab) + 2) * sizeof(char *));
	while (tab[i])
	{
		copy[i] = tab[i];
		i++;
	}
	copy[i] = NULL;
	free(tab);
	return (copy);
}

int	longest_str_len(char **strs)
{
	int	output;

	output = 0;
	while (*strs)
	{
		if (output < ft_strlen(*strs))
			output = ft_strlen(*strs);
		strs++;
	}
	return (output);
}

char	*format_row(char *original, int length)
{
	char	*output;
	int		index;
	char	original_end;

	output = zalloc(sizeof(char) * (length + 1));
	if (!output)
		return (ft_putstr_fd("Error\nMalloc error\n", 2), (char *)0);
	index = 0;
	original_end = 0;
	while (index < length)
	{
		if (!original_end && original[index] == '1')
			output[index] = '1';
		else
			output[index] = '0';
		if (!original[index])
			original_end = 1;
		index ++;
	}
	return (output);
}

t_pos	*format_map(char ***map)
{
	char	**output;
	size_t	index;
	t_pos	*size;

	size = zalloc(sizeof(t_pos));
	if (!size)
		return ((t_pos *)0);
	size->x = longest_str_len(*map);
	size->y = ft_tablen(*map);
	output = zalloc(sizeof(char *) * size->y);
	if (!output)
		return (ft_putstr_fd("Error\nMalloc error\n", 2),
			free(size), (t_pos *)0);
	index = 0;
	while ((*map)[index])
	{
		output[index] = format_row((*map)[index], size->x);
		if (!output[index])
			return (free(size), free_strs(output), (t_pos *)0);
		index ++;
	}
	*map = output;
	return (size);
}

int	init_map(char *filename, t_data *game)
{
	t_pos		*map_size;
	int			fd;
	char		**temp;

	if (access(filename, R_OK) || !has_extension(filename, ".cub"))
		return (ft_putstr_fd("Error\nInvalid filename\n", 2), 0);
	fd = open(filename, O_RDONLY);
	temp = fullread_fd(fd);
	game->map.map = parse_assets(temp, &game->assets);
	close(fd);
	if (!game->map.map || !check_map(game->map.map, &game->player))
		return (free_strs(temp), 0);
	map_size = format_map(&game->map.map);
	free_strs(temp);
	if (!map_size)
		return (0);
	game->map.size_map[1] = map_size->y;
	game->map.size_map[0] = map_size->x;
	free(map_size);
	return (1);
}


void	draw_block(int x, int y, int tile_w, int tile_h, t_data *game)
{
	int i = 0;
	int j;

	while (i < tile_w)
	{
		j = 0;
		while (j < tile_h)
		{
			my_mlx_pixel_put(&game->windata, x + i, y + j, 0x00FFFF00);
			j++;
		}
		i++;
	}
}



int	draw_map(char *name, t_data *game)
{
	if (!init_map(name, game))
		return (0);
	game->player.posx = game->player.posx + 0.5f;
	game->player.posy = game->player.posy + 0.5f;
	return (1);
}
