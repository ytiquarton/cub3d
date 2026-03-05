/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 00:02:33 by marccost          #+#    #+#             */
/*   Updated: 2026/03/06 00:02:33 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "gnl.h"
#include "cub3d.h"
#include "map_utils.h"
#include "libft.h"
#include "utils.h"

char	**ft_strsdup(char **src)
{
	char	**output;
	size_t	index;

	output = zalloc(sizeof(char **) * (ft_tablen(src) + 1));
	if (!output)
		return (0);
	index = 0;
	while (src[index])
	{
		output[index] = ft_strdup(src[index]);
		if (!output[index])
			return (free_strs(output), (char **)0);
		index ++;
	}
	return (output);
}

int	check_chars(char **map, t_pos *player_pos)
{
	size_t	index1;
	size_t	index2;
	char	playerfound;

	index1 = 0;
	playerfound = 0;
	while (map[index1])
	{
		index2 = 0;
		while (map[index1][index2])
		{
			if (!playerfound && ft_strchr("NWSE", map[index1][index2]))
			{
				playerfound = 1;
				player_pos->y = index1;
				player_pos->x = index2;
			}
			else if (!ft_strchr("10\n ", map[index1][index2]))
				return (0);
			index2++;
		}
		index1 ++;
	}
	return ((int)playerfound);
}

int	check_closed_map(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (1);
	if (x == 0 || y == 0 || map[y][x] == '\n')
		return (0);
	if (ft_strlen(map[y - 1]) <= x || !map[y + 1] || ft_strlen(map[y + 1]) <= x)
		return (0);
	map[y][x] = '1';
	return (check_closed_map(map, x + 1, y) && check_closed_map(map, x - 1, y)
		&& check_closed_map(map, x, y + 1) && check_closed_map(map, x, y - 1));
}

int	check_map(char **map, t_pos *player)
{

	map = ft_strsdup(map);
	if (!map)
		return (0);
	return (check_chars(map, player)
		&& check_closed_map(map, player->x, player->y));
}
