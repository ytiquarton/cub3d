/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:49:00 by marccost          #+#    #+#             */
/*   Updated: 2026/01/31 15:07:14 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "gnl.h"

int	check_chars(char **map)
{
	size_t	index1;
	size_t	index2;
	int		playerfound;

	index1 = 0;
	playerfound = 0;
	while (map[index1])
	{
		index2 = 0;
		while (map[index1][index2])
		{
			if (!playerfound && ft_strchr("NWSE", map[index1][index2]))
			if (!ft_strchr("nwse10\n ", map[index1][index2]))
				return (0);
			index2++;
		}
		index1 ++;
	}
	return (1);
}

int	check_map(char **map)
{

}