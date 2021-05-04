/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:26:24 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 06:24:53 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(long num)
{
	size_t	res;

	res = 0;
	if (num < 0)
	{
		num = -num;
		res++;
	}
	if (num == 0)
		res = 1;
	while (num > 0)
	{
		res++;
		num = num / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	long	num;

	num = n;
	len = ft_numlen(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len--] = '\0';
	if (num == 0)
		*res = '0';
	if (num < 0)
	{
		*res = '-';
		num = -num;
	}
	while (num > 0)
	{
		res[len--] = (char)((num % 10) + '0');
		num /= 10;
	}
	return (res);
}
