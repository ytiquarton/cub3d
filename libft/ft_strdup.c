/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:13:25 by marccost          #+#    #+#             */
/*   Updated: 2026/03/31 14:13:25 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		index;
	char	*copy;

	index = 0;
	while (src[index])
	{
		index ++;
	}
	copy = (char *)malloc(index + 1);
	if (!copy)
		return (0);
	copy[index] = 0;
	index = 0;
	while (src[index])
	{
		copy[index] = src[index];
		index ++;
	}
	return (copy);
}
