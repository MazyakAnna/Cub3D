#include "cube3d.h"

void	free_sprites(t_maze *maze)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < maze->mapsize)
	{
		j = 0;
		while (maze->map[i][j] != '\0')
		{
			if (maze->map[i][j] == '2')
				free(maze->sprites_map[i][j]);
			j++;
		}
		free(maze->sprites_map[i]);
		i++;
	}
	free(maze->sprites_map);
}

void	free_map(t_maze *maze)
{
	size_t	i;

	i = 0;
	while (i < maze->mapsize)
	{
		free(maze->map[i]);
		i++;
	}
	free(maze->map);
}

void	free_txtr(t_txtr *txtr)
{
	free(txtr->path);
	free(txtr->img->addr);
	free(txtr->img->img_ptr);
	free(txtr->img);
}

void	free_txtrs(t_maze *maze)
{	
	free_txtr((maze->north));
	free(maze->north);
	free_txtr((maze->south));
	free(maze->south);
	free_txtr((maze->west));
	free(maze->west);
	free_txtr((maze->east));
	free(maze->east);
	free_txtr((maze->sprite));
	free(maze->sprite);
}

void	break_free(t_data *data)
{
	free_sprites(data->maze);
	free_map(data->maze);
	free(data->invars.cos_dists);
	free(data->maze->player);
	free_txtrs(data->maze);
	free(data->z_buffer);
}
