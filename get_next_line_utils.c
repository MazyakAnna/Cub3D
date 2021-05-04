/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:12:59 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 03:21:01 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (res != NULL)
	{
		while (*s1 != '\0')
		{
			res[i] = *s1;
			i++;
			s1++;
		}
		res[i] = '\0';
	}
	return (res);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*res;
	size_t	i;
	size_t	len;
	size_t	count;

	len = ft_strlen(s1);
	if (ft_strlen(s1) > n)
		len = n;
	count = 0;
	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res != NULL)
	{
		while (*s1 != '\0' && count < n)
		{
			res[i] = *s1;
			i++;
			s1++;
			count++;
		}
		res[i] = '\0';
	}
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res != NULL)
	{
		while (*s1 != '\0')
		{
			res[i] = *s1;
			i++;
			s1++;
		}
		while (*s2 != '\0')
		{
			res[i] = *s2;
			i++;
			s2++;
		}
		res[i] = '\0';
	}
	return (res);
}
