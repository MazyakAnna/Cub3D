/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:04:39 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 06:23:15 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst,
		const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			dst++;
			src++;
			return (dst);
		}
		else
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			dst++;
			src++;
			i++;
		}
	}
	return (NULL);
}
