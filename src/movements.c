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

void	move_front(t_data *game)
{
	game->player.posx += 0.2f * cos(game->player.angle);
	game->player.posy += 0.2f * sin(game->player.angle);
}

void	move_left(t_data *game)
{
	game->player.posx += 0.2f * sin(game->player.angle);
	game->player.posy -= 0.2f * cos(game->player.angle);
}

void	move_rear(t_data *game)
{
	game->player.posx -= 0.2f * cos(game->player.angle);
	game->player.posy -= 0.2f * sin(game->player.angle);
}

void	move_right(t_data *game)
{
	game->player.posx -= 0.2f * sin(game->player.angle);
	game->player.posy += 0.2f * cos(game->player.angle);
}
