/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:56:12 by marccost          #+#    #+#             */
/*   Updated: 2026/03/05 23:56:34 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_strslen(char **str)
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

static void	free_strs(char **strs)
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
					return (free_strs(output), (char **)0);
			}
			last_ptr = current_ptr;
		}
		current_ptr ++;
	}
	return (output);
}
