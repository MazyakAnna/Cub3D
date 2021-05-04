/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:36:18 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 06:14:38 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	long	newlen;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	newlen = slen - start;
	if (newlen > (long)len)
		newlen = (long)len;
	if (newlen < 0)
		newlen = 0;
	ret = (char *)malloc((newlen + 1) * sizeof(char));
	if (ret != NULL)
		ft_strlcpy(ret, &s[start], newlen + 1);
	return (ret);
}
