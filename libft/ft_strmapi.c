/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:12:37 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 06:17:25 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s,
		char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	len;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret != NULL)
	{
		i = 0;
		while (i < len)
		{
			ret[i] = (*f)(i, s[i]);
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
