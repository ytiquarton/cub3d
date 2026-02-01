/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:18:11 by marccost          #+#    #+#             */
/*   Updated: 2024/10/22 20:14:22 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (1)
	{
		if (index >= n)
		{
			break ;
		}
		if (s1[index] != s2[index])
		{
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		}
		if (!s1[index] || !s1[index])
		{
			break ;
		}
		index++;
	}
	return (0);
}
