#include "cube3d.h"

void	init_t_txtr(t_txtr **txtr)
{
	*txtr = (t_txtr *)malloc(sizeof(t_txtr));
	(*txtr)->path = NULL;
	(*txtr)->size.x = 0;
	(*txtr)->size.y = 0;
	(*txtr)->size.z = 0;
	(*txtr)->img = (t_image *)malloc(sizeof(t_image));
}

t_player	*init_player(t_player *player)
{
	player = (t_player *)malloc(sizeof(t_player));
	if (player != NULL)
	{
		player->coords.x = -1;
		player->coords.y = 0;
		player->direction.x = 0;
		player->direction.y = 0;
	}
	return (player);
}

void	init_maze(t_maze *maze)
{
	fillarray(maze->resolution, 2, 0);
	init_t_txtr(&(maze->north));
	init_t_txtr(&(maze->south));
	init_t_txtr(&(maze->west));
	init_t_txtr(&(maze->east));
	init_t_txtr(&(maze->sprite));
	fillarray(maze->floor, 3, 0);
	fillarray(maze->ceilling, 3, 0);
	maze->floor_color = -1;
	maze->ceil_color = -1;
	maze->mapsize = 0;
	maze->sprites_num = 0;
	maze->sprites_map = NULL;
	maze->visible_sprites = NULL;
	maze->vis_sprts = 0;
	maze->map_list = NULL;
	maze->map_tail = NULL;
	maze->map = NULL;
	maze->player = init_player(maze->player);
}
