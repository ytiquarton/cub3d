/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:47:38 by marccost          #+#    #+#             */
/*   Updated: 2026/03/05 23:47:53 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_UTILS_H
# define ASSETS_UTILS_H
# include "cub3d.h"

int		check_loaded_assets(t_assets *assets);
void	free_assets(t_assets *assets);
#endif