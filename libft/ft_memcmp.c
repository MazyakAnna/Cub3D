/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:54:20 by bmaegan           #+#    #+#             */
/*   Updated: 2020/11/14 19:12:55 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (n != 0)
	{
		p1 = (unsigned char *)s1;
		p2 = (unsigned char *)s2;
		while (n != 0)
		{
			if (*p1 != *p2)
				return (*p1 - *p2);
			p1++;
			p2++;
			n--;
		}
	}
	return (0);
}
