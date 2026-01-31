/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:26 by marccost          #+#    #+#             */
/*   Updated: 2025/04/03 16:33:16 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	return (dest + index);
}

static void	fillstr(char *dest, int size, char **strs, char *sep)
{
	int		index;
	char	*catptr;

	catptr = dest;
	index = 0;
	while (index < size - 1)
	{
		catptr = ft_strcpy(catptr, strs[index]);
		catptr = ft_strcpy(catptr, sep);
		index ++;
	}
	catptr = ft_strcpy(catptr, strs[index]);
	*catptr = 0;
}

static char	*ft_strsjoin(int size, char **strs, char *sep)
{
	char	*output;
	int		index;
	int		output_size;

	output_size = 0;
	if (size <= 0)
		return (malloc(0));
	index = 0;
	while (index < size)
	{
		output_size += ft_strlen(strs[index]);
		index ++;
	}
	output_size += (size - 1) * ft_strlen(sep) + 1;
	output = malloc(output_size);
	if (!output)
		return (0);
	fillstr(output, size, strs, sep);
	return (output);
}

char	*ft_strjoin(char const *s1, char const	*s2)
{
	char	*strs[2];

	strs[0] = (char *)s1;
	strs[1] = (char *)s2;
	return (ft_strsjoin(2, strs, ""));
}
