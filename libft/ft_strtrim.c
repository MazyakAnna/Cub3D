/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:48:24 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 06:15:37 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iscinstr(char c, char const *str)
{
	int	check;

	check = 0;
	while (*str != '\0')
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (check);
}

/*
** Function that returns start of the trimmed str
** and returns its end using a pointer;
** The first WHILE -- searches the start = i;
** The second WHILE -- searches its end = len - j;
*/

static size_t	ft_trimmedstart(char const *s1,
				char const *set, size_t *end)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && ft_iscinstr(s1[i], set))
		i++;
	while (ft_iscinstr(s1[*end - j - 1], set) && (i + j < *end))
		j++;
	*end = *end - j;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*res;
	size_t	start;
	size_t	end;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	end = len;
	start = ft_trimmedstart(s1, set, &end);
	ret = (char *)malloc((end - start + 1) * sizeof(char));
	if (ret != NULL)
	{
		res = ret;
		while (start != end)
		{
			*res = s1[start];
			start++;
			res++;
		}
		*res = '\0';
	}
	return (ret);
}
