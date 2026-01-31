/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:23:13 by marccost          #+#    #+#             */
/*   Updated: 2024/10/22 23:52:06 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	char	*space;
	int		index;

	index = 0;
	space = "\t\n\v\f\r ";
	while (space[index])
	{
		if (space[index] == c)
		{
			return (1);
		}
		index ++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	returnvalue;
	int	sign;

	returnvalue = 0;
	sign = 1;
	index = 0;
	while (str[index] && is_space(str[index]))
		index ++;
	if (str[index] && (str[index] == '+' || str[index] == '-'))
	{
		if (str[index] == '-')
		{
			sign *= -1;
		}
		index ++;
	}
	while (str[index] && ft_isdigit(str[index]))
	{
		returnvalue *= 10;
		returnvalue -= str[index] - '0';
		index ++;
	}
	return (returnvalue * sign * -1);
}
