/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:28:50 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 06:19:18 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ret != NULL)
	{
		res = ret;
		while (*s1 != '\0')
		{
			*res = *s1;
			res++;
			s1++;
		}
		*res = '\0';
	}
	return (ret);
}
