/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:36:21 by marccost          #+#    #+#             */
/*   Updated: 2024/10/07 13:46:35 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	int		index0;

	if (!(*needle))
		return ((char *)haystack);
	index = 0;
	while (haystack[index] && index < len)
	{
		if (haystack[index] == *needle)
		{
			index0 = 0;
			while (needle[index0] && needle[index0] == haystack[index + index0])
			{
				index0 ++;
			}
			if (!needle[index0])
			{
				if (index + index0 > len)
					return (0);
				return ((char *)haystack + index);
			}
		}
		index++;
	}
	return (0);
}
