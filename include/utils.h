/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:52:40 by marccost          #+#    #+#             */
/*   Updated: 2026/03/03 20:23:39 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "cub3d.h"

int	is_valid_num(char *str);
int	ft_tablen(char **tab);
int	is_in_block(int x, int y, t_data *game);
#endif