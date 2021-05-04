/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:53:29 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 06:17:04 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	isinside(const char *haystack, const char *needle)
{
	while (*needle != '\0')
	{
		if (*haystack == *needle)
		{
			haystack++;
			needle++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (needle[0] == '\0' || (haystack == NULL && len == 0))
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack != '\0' && (needle_len++) <= len)
	{
		if (isinside(haystack, needle))
			return ((char *)haystack);
		else
			haystack++;
	}
	return (NULL);
}
