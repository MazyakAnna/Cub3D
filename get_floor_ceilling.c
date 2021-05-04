/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_ceilling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 04:13:56 by bmaegan           #+#    #+#             */
/*   Updated: 2021/05/04 07:55:49 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	getRGBchannel (char *line, int *i, int *channel)
{
	int		numlen;
	char	*numstr;

	numlen = 0;
	*i += count_chars(line + *i, ' ');
	while (ft_isdigit(line[*i + numlen]))
		numlen++;
	if (numlen > 0 && (line[*i + numlen] == ' '
			|| line[*i + numlen] == ',' || line[*i + numlen] == '\0'))
	{
		numstr = (char *)malloc(sizeof(char) * (numlen + 1));
		if (!numstr)
			return (5);
		numstr = ft_strncpy(numstr, line + *i, numlen);
		*i += numlen;
		numlen = ft_atoi(numstr);
		free(numstr);
		if (numlen > 255)
			return (5);
		*channel = numlen;
		return (0);
	}
	return (4);
}

int	get_RGB(char *line, int i, int *RGB)
{
	int	errno;
	int	num;

	errno = 0;
	num = 0;
	i += count_chars(line + i, ' ');
	while (errno == 0 && num < 3)
	{
		errno = getRGBchannel(line, &i, RGB + num);
		num++;
		i += count_chars(line + i, ' ');
		if (num < 3 && line[i] != ',')
			return (5);
		else if (num == 3 && line[i] != '\0')
			return (4);
		i++;
	}
	return (errno);
}

int	get_floor(char *line, t_maze *maze, int i, t_errors *errors)
{
	int	error;

	if (errors->F != 1)
		return (2);
	error = get_RGB(line, i + 1, maze->floor);
	if (error != 0)
	{
		maze->floor[0] = -1;
		maze->floor[1] = -1;
		maze->floor[2] = -1;
	}
	else
		maze->floor_color = RGB_to_color(maze->floor);
	return (error);
}

int	get_ceilling(char *line, t_maze *maze, int i, t_errors *errors)
{
	int	error;

	if (errors->C != 1)
		return (2);
	error = get_RGB(line, i + 1, maze->ceilling);
	if (error != 0)
	{
		maze->ceilling[0] = -1;
		maze->ceilling[1] = -1;
		maze->ceilling[2] = -1;
	}
	else
		maze->ceil_color = RGB_to_color(maze->ceilling);
	return (error);
}
