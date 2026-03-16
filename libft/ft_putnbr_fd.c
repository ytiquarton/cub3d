/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:52:16 by marccost          #+#    #+#             */
/*   Updated: 2024/10/22 23:46:54 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	char	toprint;

	if (nb < 0)
		write(fd, "-", 1);
	else
		nb *= -1;
	if (nb < -9)
		ft_putnbr_fd(-(nb / 10), fd);
	toprint = -(nb % 10) + '0';
	write(fd, &toprint, 1);
	return ;
}
