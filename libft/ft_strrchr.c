/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:16:15 by marccost          #+#    #+#             */
/*   Updated: 2024/10/07 12:30:00 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	temp = s;
	while (*s)
		s++;
	while (s >= temp)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
