/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:53:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/04/29 06:20:27 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	res;

	res = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			res++;
			s++;
		}
		while (*s != c && *s != '\0')
			s++;
	}
	return (res);
}

static	void	*ft_freewords(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i <= index)
	{
		free(arr[index]);
		i++;
	}
	free(arr);
	return (NULL);
}

static	char	**ft_fillarray(char **ret, const char *s, char c)
{
	size_t	word_index;
	size_t	i;
	size_t	j;

	i = 0;
	word_index = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != '\0' && s[j] != c)
			j++;
		if (j != i)
		{
			ret[word_index] = (char *)malloc((j - i + 1) * sizeof(char));
			if (ret[word_index] == NULL)
				return (ft_freewords(ret, word_index));
			ft_strlcpy(ret[word_index], &s[i], j - i + 1);
			word_index++;
		}
		i = j;
	}
	return (ret);
}

char	**ft_split(char const *str, char c)
{
	char	**ret;
	size_t	words;

	if (str == NULL)
		return (NULL);
	words = ft_countwords(str, c);
	ret = (char **)malloc((words + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ret = ft_fillarray(ret, str, c);
	if (ret == NULL)
		return (ret);
	ret[words] = NULL;
	return (ret);
}
