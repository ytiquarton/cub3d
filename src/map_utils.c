/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:33:28 by marccost          #+#    #+#             */
/*   Updated: 2026/01/31 16:33:28 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "gnl.h"
#include <fcntl.h>
#include <stdio.h>

void	*zalloc(size_t	size)
{
	char	*output;
	size_t	index;

	output = malloc(size);
	if (!output)
		return (0);
	index = 0;
	while (index < size)
	{
		output[index] = 0;
		index ++;
	}
	return ((void *)output);
}

void	free_strs(char **strs)
{
	size_t	index;

	index = 0;
	while (strs[index])
	{
		free(strs[index]);
		index++;
	}
	free(strs);
}

size_t	strs_len(char **strs)
{
	size_t	index;

	index = 0;
	while (strs[index])
		index ++;
	return (index);
}

char	**free_strs_join(char **strs1, char **strs2)
{
	char	**output;
	size_t	index1;
	size_t	index2;

	output = zalloc((strs_len(strs1) + strs_len(strs2) + 1) * sizeof(char **));
	if (!output)
		return (free_strs(strs1), free_strs(strs2), (char **)0);
	index1 = 0;
	while (strs1[index1])
	{
		output[index1] = strs1[index1];
		index1 ++;
	}
	index2 = 0;
	while (strs2[index2])
	{
		output[index1 + index2] = strs2[index2];
		index2 ++;
	}
	free(strs1);
	free(strs2);
	return (output);
}

char	**fullread_fd(int fd)
{
	char	**output;
	char	**temp;

	output = zalloc(sizeof(char *) * 1);
	if (!output)
		return (0);
	while (1)
	{
		temp = zalloc(sizeof(char *) * 2);
		if (!temp)
			return (free_strs(output), (char **)0);
		temp[0] = get_next_line(fd);
		if (!temp[0])
			break ;
		output = free_strs_join(output, temp);
		if (!output)
			return (0);
	}
	free_strs(temp);
	return (output);
}
