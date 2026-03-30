/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:00:13 by marccost          #+#    #+#             */
/*   Updated: 2026/03/16 18:00:16 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_file_extension(char *file)
{
	size_t	index;

	index = ft_strlen(file);
	while (--index > 0)
	{
		if (file[index] == '.')
			return (file + index);
	}
	return (0);
}

int	has_extension(char *file, char *extension)
{
	char	*file_extension;

	file_extension = get_file_extension(file);
	if (!file_extension)
		return (0);
	return (!ft_strncmp(file_extension, extension, ft_strlen(extension) + 1));
}
