/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 03:58:17 by bmaegan           #+#    #+#             */
/*   Updated: 2021/03/05 12:17:33 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	read_number(int fd, int *ret, char *buf)
{
	int	i;
	int	check;

	i = 0;
	check = read(fd, buf, 1);
	check = read(fd, buf, 1);
	while (ft_isdigit(buf[0]) && check > 0)
	{
		i = i * 10 + buf[0] - 0x30;
		check = read(fd, buf, 1);
	}
	*ret = i;
	return (check);
}

int	read_strctr_size(int fd, t_intcoords *size, char *buf)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (i < 3 && check > 0)
	{
		check = read(fd, buf, 1);
		if (buf[0] == '\n')
			i++;
	}
	check = read_number(fd, &size->x, buf);
	check = read_number(fd, &size->y, buf);
	return (check);
}

int	check_path(char *path, t_intcoords *size)
{
	int		check;
	char	buf[2];
	int		fd;

	check = 1;
	fd = open(path, O_RDONLY);
	if (fd >= 0)
	{
		check = read_strctr_size(fd, size, buf);
		close(fd);
	}
	else
	{
		check = 0;
		close (fd);
	}
	return (check);
}

/*
** trims line to path ---> puts path into *path by address ---> check_path
** returns errno;
** 0 -> WOW COOL IT'S WORKING
** 5 -> OUCH WRONG PATH
** 4 -> too much arguments (more than one)
*/
int	get_texture(char *line, int i, char **path, t_intcoords *size)
{
	int	len;

	i += count_chars(&(line[i]), ' ');
	len = i;
	while ((line[len] != ' ' || line[len - 1] == '\x5c') && line[len] != '\0')
		len++;
	*path = ft_strndup(&(line[i]), len - i);
	len += count_chars(&(line[len]), ' ');
	if (line[len] == '\0')
	{
		if (check_path(*path, size) > 0)
			return (0);
		else
			freenull(*path);
		return (5);
	}
	return (4);
}

/*
** MAZE->SPRITE <---------- get_texture(texture_path)
*/
int	get_sprite(char *line, t_maze *maze, int i, t_errors *errors)
{
	int			error;
	char		*path;
	t_intcoords	size;

	if (errors->S != 1)
		return (2);
	path = NULL;
	error = get_texture(line, i + 1, &path, &size);
	if (error == 0)
	{
		maze->sprite->path = path;
		maze->sprite->size = size;
	}
	return (error);
}
