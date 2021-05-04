/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:29:33 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 06:22:19 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	*ret;

	ret = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*(char *)dst = *(char *)src;
		src++;
		dst++;
		i++;
	}
	return (ret);
}
