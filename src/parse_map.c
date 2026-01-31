/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:45:55 by marccost          #+#    #+#             */
/*   Updated: 2026/01/31 16:47:08 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map_utils.h"
#include "map_check.h"

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


int	init_map(int fd, t_data *game)
{
	t_pos	player;
	int		y;

	y = 0;
	game->map.map = fullread_fd(fd);
	if (!game->map.map || check_map(game->map.map, player))
		return (0);
	game->map.size_map[1] = y;
	game->map.size_map[0] = ft_strlen(game->map.map[0]) - 1;
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



void	draw_map(char *name, t_data *game)
{
	int fd;
	int i;
	int j;
	int tile_w;
	int tile_h;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return ;
	init_map(fd, game);
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

			if (game->map.map[i][j] == 'P')
			{
				game->player.posx = j * tile_w + tile_w / 2;
				game->player.posy = i * tile_h + tile_h / 2;
			}
			j++;
		}
		i++;
	}
}