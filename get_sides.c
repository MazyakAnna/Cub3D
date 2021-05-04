/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sides.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 03:20:51 by bmaegan           #+#    #+#             */
/*   Updated: 2021/02/28 10:20:43 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
** MAZE->NORTH <---------- get_texture(texture_path)
*/
int	get_north(char *line, t_maze *maze, int i, t_errors *errors)
{
	int			error;
	char		*path;
	t_intcoords	size;

	if (errors->NO != 1)
		return (2);
	path = NULL;
	error = get_texture(line, i + 2, &path, &size);
	if (error == 0)
	{
		maze->north->path = path;
		maze->north->size = size;
	}
	return (error);
}

/*
** MAZE->SOUTH <---------- get_texture(texture_path)
*/
int	get_south(char *line, t_maze *maze, int i, t_errors *errors)
{
	int			error;
	char		*path;
	t_intcoords	size;

	if (errors->SO != 1)
		return (2);
	path = NULL;
	error = get_texture(line, i + 2, &path, &size);
	if (error == 0)
	{
		maze->south->path = path;
		maze->south->size = size;
	}
	return (error);
}

/*
** MAZE->EAST <---------- get_texture(texture_path)
*/
int	get_east(char *line, t_maze *maze, int i, t_errors *errors)
{
	int			error;
	char		*path;
	t_intcoords	size;

	if (errors->EA != 1)
		return (2);
	path = NULL;
	error = get_texture(line, i + 2, &path, &size);
	if (error == 0)
	{
		maze->east->path = path;
		maze->east->size = size;
	}
	return (error);
}

/*
** MAZE->WEST <---------- get_texture(texture_path)
*/
int	get_west(char *line, t_maze *maze, int i, t_errors *errors)
{
	int			error;
	char		*path;
	t_intcoords	size;

	if (errors->WE != 1)
		return (2);
	path = NULL;
	error = get_texture(line, i + 2, &path, &size);
	if (error == 0)
	{
		maze->west->path = path;
		maze->west->size = size;
	}
	return (error);
}
