#include "cube3d.h"

int	is_cub(char *line)
{
	int	len;

	if (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == 'b'
			&& line[len - 2] == 'u'
			&& line[len - 3] == 'c'
			&& line[len - 4] == '.')
			return (1);
	}
	return (0);
}

int	check_flag(char *line, char *flag)
{
	int	i;

	if (line != NULL && flag != NULL)
	{
		i = 0;
		while (line[i] != '\0' && flag[i] != '\0')
		{
			if (line[i] == flag[i])
				i++;
			else
				return (0);
		}
		if (line[i] == '\0' && flag[i] == '\0')
			return (1);
	}
	return (0);
}

int	check_cub_file(char *filepath, t_maze *maze, t_errors *errors)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		printf("Не удалось открыть .cub файл. Проверьте его местонахождение\n");
		return (-1);
	}
	*errors = input_data(maze, fd);
	close(fd);
	errors->map = check_map(maze);
	print_params(maze);
	return (0);
}
