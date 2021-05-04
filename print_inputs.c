#include "cube3d.h"

void	print_map(char **coords)
{
	long	i;

	i = 0;
	if (coords != NULL)
	{
		while (coords[i] != NULL)
		{
			ft_putstr_fd(coords[i], 1);
			write(1, "\n", 1);
			i++;
		}
	}
}

void	print_sprites_map(t_sprite ***sprites_map, int mapsize, char **map)
{
	int	j;
	int	i;
	int	len;

	i = 0;
	while (i < mapsize)
	{
		len = ft_strlen(map[i]);
		j = 0;
		while (j < len)
		{
			if (sprites_map[i][j] != NULL)
				ft_putchar_fd(sprites_map[i][j]->type, 1);
			else
				ft_putchar_fd('0', 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	print_params_txtrs(t_maze *maze)
{
	ft_putstr_fd("\nNorth = ", 1);
	ft_putstr_fd(maze->north->path, 1);
	ft_putstr_fd("\nSouth = ", 1);
	ft_putstr_fd(maze->south->path, 1);
	ft_putstr_fd("\nWest = ", 1);
	ft_putstr_fd(maze->west->path, 1);
	ft_putstr_fd("\nEast = ", 1);
	ft_putstr_fd(maze->east->path, 1);
	ft_putstr_fd("\nSprite = ", 1);
	ft_putstr_fd(maze->sprite->path, 1);
	ft_putstr_fd("\nFloor = ", 1);
}

void	print_params(t_maze *maze)
{
	write(1, "\n", 1);
	ft_putnbr_fd(maze->resolution[0], 1);
	write(1, " ", 1);
	ft_putnbr_fd(maze->resolution[1], 1);
	print_params_txtrs(maze);
	ft_putnbr_fd(maze->floor[0], 1);
	write(1, ",", 1);
	ft_putnbr_fd(maze->floor[1], 1);
	write(1, ",", 1);
	ft_putnbr_fd(maze->floor[2], 1);
	ft_putstr_fd("\nCeilling = ", 1);
	ft_putnbr_fd(maze->ceilling[0], 1);
	write(1, ",", 1);
	ft_putnbr_fd(maze->ceilling[1], 1);
	write(1, ",", 1);
	ft_putnbr_fd(maze->ceilling[2], 1);
	write(1, "\n", 1);
	print_map(maze->map);
}
