#include "cube3d.h"

/*
** 2 -> ERROR! Zero borders with empty space
*/
int	neighbours_are_empty(char **coords, size_t i, size_t j)
{
	if (ft_strlen(coords[i - 1]) < (j - 1)
		|| coords[i - 1][j] == ' ' || coords[i][j - 1] == ' '
		|| coords[i][j + 1] == ' ' || coords[i][j + 1] == '\0')
		return (2);
	else if (ft_strlen(coords[i + 1]) < (j - 1)
		|| coords[i + 1][j] == ' ')
		return (2);
	return (0);
}

/*
** 6 -> ERROR! More than one player!
** 7 -> ERROR! Player borders with empty space!
*/
int	check_player(t_maze *maze, size_t i, size_t *j, char c)
{
	if (maze->player->coords.x != -1)
		return (6);
	else if (neighbours_are_empty(maze->map, i, *j) != 0)
		return (7);
	maze->player->coords.x = i + 0.1;
	maze->player->coords.y = *j + 0.1;
	if (c == 'N' || c == 'S')
	{
		maze->player->direction.y = 0;
		if (c == 'N')
			maze->player->direction.x = -1;
		else
			maze->player->direction.x = 1;
	}
	else if (c == 'W' || c == 'E')
	{
		maze->player->direction.x = 0;
		if (c == 'W')
			maze->player->direction.y = 1;
		else
			maze->player->direction.y = -1;
	}
	maze->map[i][*j] = '0';
	*j += 1;
	return (0);
}

/*
** auxiliary/additional function that checks
** if the line contains only '1', '2' and ' ';
** input: the first or the last line of the map;
** return values: 0 if it contains only wall, sprite or spaces
** positive num -- if contains any other symbol
** 4 -> hole or wrong symbol in the first mapstring!
*/
int	check_wall(char *mapline)
{
	size_t	j;

	j = 0;
	while (mapline[j] != '\0')
	{
		if (mapline[j] == '1' || mapline[j] == ' ')
			j++;
		else
			return (4);
	}
	return (0);
}

/*
** auxiliary/additional function
** for checking lines between the last and the first
** input values: pointer to map and the number of the checking line
** 8 -> ERROR! Unknown symbol in map!
*/
int	check_middleline(t_maze *maze, size_t i)
{
	size_t	j;
	int		error;
	char	c;

	j = 1;
	error = 0;
	while (maze->map[i][j] != '\0' && error == 0)
	{
		c = maze->map[i][j];
		if (c == '1' || c == ' ')
			j++;
		else if (c == '0' || c == '2')
		{
			if (c == '2')
				maze->sprites_num++;
			error = neighbours_are_empty(maze->map, i, j);
			j++;
		}
		else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			error = check_player(maze, i, &j, c);
		else
			error = 8;
	}
	return (error);
}

/*
** 3 -> hole or wrong symbol in the left part of the map
*/
int	check_map(t_maze *maze)
{
	size_t	i;
	int		error;

	error = check_wall(maze->map[0]);
	if (error != 0)
		return (error);
	i = 1;
	while (i < (maze->mapsize - 1))
	{
		if (maze->map[i][0] == '1' || maze->map[i][0] == ' ')
		{
			error = check_middleline(maze, i);
			if (error != 0)
				return (error);
		}
		else
			return (3);
		i++;
	}
	error = check_wall(maze->map[maze->mapsize - 1]);
	if (maze->player->coords.x == -1)
		return (5);
	return (error);
}
