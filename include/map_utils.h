/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:38:54 by marccost          #+#    #+#             */
/*   Updated: 2026/01/31 16:38:54 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H
# include <aio.h>

char	**fullread_fd(int fd);
void	free_strs(char **strs);
size_t	strs_len(char **strs);
void	*zalloc(size_t size);
#endif