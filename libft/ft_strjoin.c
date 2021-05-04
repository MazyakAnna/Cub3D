/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:40:57 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 06:18:55 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ret != NULL)
	{
		res = ret;
		while (*s1 != '\0')
		{
			*res = *s1;
			res++;
			s1++;
		}
		while (*s2 != '\0')
		{
			*res = *s2;
			res++;
			s2++;
		}
		*res = '\0';
	}
	return (ret);
}
