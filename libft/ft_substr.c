/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:13:33 by marccost          #+#    #+#             */
/*   Updated: 2024/10/28 18:01:41 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;

	if ((unsigned int)ft_strlen((char *)s) <= start)
		output = malloc(1);
	else if ((size_t)ft_strlen((char *)s + start) < len)
		output = malloc(ft_strlen((char *)s + start) + 1);
	else
		output = malloc(len + 1);
	if (!output)
		return (0);
	if (len + 1 < len)
		len -= 1;
	ft_strlcpy(output, (char *)s + start * ((unsigned int)ft_strlen(
				(char *)s) > start), len * (size_t)((unsigned int)ft_strlen(
				(char *)s) > start) + 1);
	return (output);
}
