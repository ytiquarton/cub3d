/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:12 by marccost          #+#    #+#             */
/*   Updated: 2025/04/03 16:32:18 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numblen(int numb)
{
	int	nblen;

	nblen = (numb <= 0);
	numb = numb * (2 * (numb < 0) - 1);
	while (numb < 0)
	{
		numb /= 10;
		nblen ++;
	}
	return (nblen);
}

char	*ft_itoa(int n)
{
	char	*output;
	int		index;
	int		sign;

	output = malloc(ft_numblen(n) + 1);
	if (!output)
		return (0);
	output[ft_numblen(n)] = 0;
	sign = (n < 0);
	index = ft_numblen(n) - 1;
	n = n * (2 * (n < 0) - 1);
	while (index >= 0)
	{
		output[index] = -(n % 10) + '0';
		n /= 10;
		index --;
	}
	if (sign)
		output[0] = '-';
	return (output);
}
