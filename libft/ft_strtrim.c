/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:19:37 by marccost          #+#    #+#             */
/*   Updated: 2025/04/03 16:33:34 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_inset(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n && src[index])
	{
		dest [index] = src[index];
		index ++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index ++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*returnstring;

	start = 0;
	while (ft_inset(((char *)s1)[start], (char *)set) && s1[start])
	{
		start ++;
	}
	end = ft_strlen((char *)s1) - 1;
	while (end >= 0 && ft_inset(((char *)s1)[end], (char *)set))
	{
		end--;
	}
	end ++;
	if (end == 0)
		end = start;
	returnstring = malloc(sizeof(char) * (end - start + 1));
	if (!returnstring)
		return (0);
	ft_strncpy(returnstring, (char *)s1 + start, end - start);
	returnstring[end - start] = 0;
	return (returnstring);
}
