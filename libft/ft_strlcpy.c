/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:48:02 by marccost          #+#    #+#             */
/*   Updated: 2024/10/28 17:15:02 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;

	index = 0;
	if (size != 0)
	{
		while (src[index] && (index < (size - 1)))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = 0;
	}
	while (src[index])
	{
		index++;
	}
	return (index);
}
