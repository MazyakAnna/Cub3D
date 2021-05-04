#include "cube3d.h"

void	clear_maze(t_maze *maze)
{
	size_t	i;

	i = 0;
	ft_lstclear(&(maze->map_list), free);
	maze->north = freenull(maze->north);
	maze->south = freenull(maze->south);
	maze->sprite = freenull(maze->sprite);
	maze->west = freenull(maze->west);
	maze->east = freenull(maze->east);
	while (i < maze->mapsize)
	{
		maze->map[i] = freenull(maze->map[i]);
		i++;
	}
	maze->map = freenull(maze->map);
}

void	parse_walls(t_maze *maze, char *line, t_errors *errors, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
		errors->NO = get_north(line, maze, i, errors);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		errors->WE = get_west(line, maze, i, errors);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		errors->EA = get_east(line, maze, i, errors);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		errors->SO = get_south(line, maze, i, errors);
}

void	parse_floor_ceil(t_maze *maze, char *line, t_errors *errors, int i)
{
	if (line[i] == 'F')
		errors->F = get_floor(line, maze, i, errors);
	else if (line[i] == 'C')
		errors->C = get_ceilling(line, maze, i, errors);
}

int	input_params(t_maze *maze, char *line, t_errors *errors, t_list **map_head)
{
	int	i;

	i = count_chars(line, ' ');
	if (line[i] == 'R')
		errors->R = get_resolution(line, maze, i, errors);
	else if ((line[i] == 'N' && line[i + 1] == 'O')
		|| (line[i] == 'W' && line[i + 1] == 'E')
		|| (line[i] == 'E' && line[i + 1] == 'A')
		|| (line[i] == 'S' && line[i + 1] == 'O'))
		parse_walls(maze, line, errors, i);
	else if (line[i] == 'S')
		errors->S = get_sprite(line, maze, i, errors);
	else if (line[i] == 'F' || line[i] == 'C')
		parse_floor_ceil(maze, line, errors, i);
	else if (line[i] == '1')
	{
		errors->map = get_map(map_head, &(maze->map_tail), line);
		return (1);
	}
	else
		errors->others = is_empty_line(line, i);
	freenull(line);
	return (0);
}

/*
** basically it's the parser
*/
t_errors	input_data(t_maze *maze, int fd)
{
	int			eof;
	char		*line;
	t_errors	errors;

	init_errors(&errors);
	eof = get_next_line(fd, &line);
	while (eof > 0)
	{
		if (maze->mapsize == 0)
			maze->mapsize = input_params(maze, line,
					&errors, &(maze->map_list));
		else
		{
			errors.map = get_map(&(maze->map_list), &(maze->map_tail), line);
			maze->mapsize++;
		}
		if (errors.others != 0)
			return (errors);
		eof = get_next_line(fd, &line);
	}
	if (eof != 0)
		errors.others = -100;
	maplist_to_map(maze, maze->map_list);
	free(line);
	return (errors);
}
