#include "cube3d.h"

int	select_num_resolution(char *line, int *num, int *i, int max)
{
	char	*strnum;
	int		numlen;

	*i += count_chars(line + *i, ' ');
	numlen = 0;
	while (line[*i + numlen] >= '0' && line[*i + numlen] <= '9')
		numlen++;
	if (numlen > 4)
	{
		*i += numlen;
		*num = max;
		return (0);
	}
	if (numlen == 0 || (line[*i + numlen] != ' ' && line[*i + numlen] != '\0'))
		return (3);
	strnum = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!strnum)
		return (999);
	strnum = ft_strncpy(strnum, line + *i, numlen);
	*i += numlen;
	*num = ft_atoi(strnum);
	if (*num > max)
		*num = max;
	free(strnum);
	return (0);
}

int	get_resolution(char *line, t_maze *maze, int i, t_errors *errors)
{
	int	errno;

	if (errors->R != 1)
		return (2);
	i++;
	errno = select_num_resolution(line, maze->resolution, &i, MAX_WIDTH);
	if (errno != 0)
		return (errno);
	errno = select_num_resolution(line, maze->resolution + 1, &i, MAX_HEIGHT);
	if (errno != 0)
		return (errno + 1);
	i += count_chars(line + i, ' ');
	if (line[i] != '\0')
		return (5);
	return (0);
}

int	is_empty_line(char *line, int i)
{
	if (line[i] == '\n')
		return (0);
	else
		return (line[i]);
}
