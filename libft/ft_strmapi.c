/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:14:19 by marccost          #+#    #+#             */
/*   Updated: 2024/10/22 23:25:34 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	int		index;

	output = malloc(ft_strlen((char *)s) + 1);
	if (!output)
		return (0);
	index = 0;
	while (s[index])
	{
		output[index] = (*f)(index, s[index]);
		index ++;
	}
	output[index] = 0;
	return (output);
}
