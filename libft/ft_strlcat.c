/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:21:08 by marccost          #+#    #+#             */
/*   Updated: 2024/10/22 17:50:47 by marccost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_len;
	unsigned int	index;

	dst_len = ft_strlen(dest);
	index = dst_len;
	while (size && index < size - 1 && src[index - dst_len])
	{
		dest[index] = src[index - dst_len];
		index ++;
	}
	if (size && dst_len <= size)
	{
		dest[index] = 0;
	}
	if (size < dst_len)
	{
		return (size + ft_strlen(src));
	}
	return (dst_len + ft_strlen(src));
}

// void forceprintf(char *str, int size)
// {
// 	int index = 0;

// 	while (index < size)
// 	{
// 		printf("%c",str[index]);
// 		index ++;
// 	}
// }

// int main()
// {
// 	char	dest[100] = "aaaa";
// 	char	src[] = "xyz\0a";
// 	char	dest1[100] = "aaaa";
// 	char	src1[] = "xyz\0a";

// 	unsigned int test = ft_strlcat(dest,src,0);
// 	unsigned int test1 = strlcat(dest1,src1,0);

// 	printf("%d : %d : ", test, str_len(dest));
// 	forceprintf(dest,6);
// 	printf(" : ");
// 	forceprintf(src,4);
// 	printf("\n");

// 	printf("%d : %d : ",test1, str_len(dest1));
// 	forceprintf(dest1,6);
// 	printf(" : ");
// 	forceprintf(src1,4);
// 	printf("\n");
// }