/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:39:43 by marccost          #+#    #+#             */
/*   Updated: 2024/06/27 17:53:11 by marccost         ###   ########.fr       */
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
