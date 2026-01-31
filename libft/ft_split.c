/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:42:19 by aloubry           #+#    #+#             */
/*   Updated: 2025/04/03 16:32:51 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_strslen(char **str)
{
	int	len;

	len = 0;
	while (*(str + len))
	{
		len++;
	}
	return (len);
}

static int	add_str_to_str_array(char *startptr,
char *endptr, char **str_array)
{
	int		index;
	char	*added_string;

	added_string = malloc((endptr - startptr + 1) * sizeof(char *));
	if (!added_string)
		return (0);
	index = 0;
	while (index < endptr - startptr)
	{
		added_string[index] = startptr[index];
		index ++;
	}
	added_string[index] = 0;
	str_array[ft_strslen(str_array)] = added_string;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**output;
	char	*last_ptr;
	char	*current_ptr;

	current_ptr = (char *)str;
	last_ptr = (char *)str - 1;
	output = malloc((ft_strlen((char *)str) / 2 + 2) * sizeof(char *));
	if (!output)
		return (0);
	ft_bzero(output, (ft_strlen((char *)str) / 2 + 2) * sizeof(char *));
	while (current_ptr < str + ft_strlen((char *)str) + 1)
	{
		if (*current_ptr == c || *current_ptr == 0)
		{
			if (current_ptr - last_ptr > 1)
			{
				if (!add_str_to_str_array(last_ptr + 1, current_ptr, output))
					return (0);
			}
			last_ptr = current_ptr;
		}
		current_ptr ++;
	}
	return (output);
}
