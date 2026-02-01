/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:34:42 by marccost          #+#    #+#             */
/*   Updated: 2026/01/31 17:44:29 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map_utils.h"
#include "map_check.h"
#include "libft.h"

char	**add_one_malloc(char **tab)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc((ft_tablen(tab) + 2) * sizeof(char *));
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
		return (0);
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
		return (free(size), (t_pos *)0);
	index = 0;
	while ((*map)[index])
	{
		output[index] = format_row((*map)[index], size->x);
		if (!output[index])
			return (free(size), free_strs(output), (t_pos *)0);
		index ++;
	}
	free_strs(*map);
	*map = output;
	return (size);
}

int	init_map(int fd, t_data *game)
{
	t_pos	player;
	t_pos	*map_size;

	game->map.map = fullread_fd(fd);
	if (!game->map.map || !check_map(game->map.map, &player))
		return (free_strs(game->map.map), 0);
	map_size = format_map(&game->map.map);
	if (!map_size)
		return (free_strs(game->map.map), 0);
	game->map.size_map[1] = map_size->y;
	game->map.size_map[0] = map_size->x;
	free(map_size);
	game->player.posx = player.x;
	game->player.posy = player.y;
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
	int fd;
	int i;
	int j;
	int tile_w;
	int tile_h;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!init_map(fd, game))
		return (close(fd), 0);
	close(fd);
	tile_w = 1920 / game->map.size_map[0];
	tile_h = 1080 / game->map.size_map[1];
	i = 0;
	while (i < game->map.size_map[1])
	{
		j = 0;
		while (j < game->map.size_map[0])
		{
			if (game->map.map[i][j] == '1')
				draw_block(j * tile_w, i * tile_h, tile_w, tile_h, game);
			j++;
		}
		i++;
	}
	game->player.posx = game->player.posx * tile_w + tile_w / 2;
	game->player.posy = game->player.posy * tile_h + tile_h / 2;
	return (1);
}
