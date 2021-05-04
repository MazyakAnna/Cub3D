#include "cube3d.h"

double	dist_sqr(double x, double y, t_coords *plcoords)
{
	double	dx;
	double	dy;

	dx = x - plcoords->x;
	dy = y - plcoords->y;
	return (dx * dx + dy * dy);
}

t_sprite	*create_sprite(int i, int j, char c)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	sprite->x = i + 0.5;
	sprite->y = j + 0.5;
	sprite->dist_sqr = 0;
	sprite->int_x = i;
	sprite->int_y = j;
	sprite->type = c;
	sprite->visible = 1;
	sprite->next = NULL;
	return (sprite);
}

t_sprite	***create_sprites_map(char **map, size_t mapsize)
{
	t_sprite	***sprite_map;
	size_t		i;
	size_t		j;
	size_t		line_len;

	sprite_map = NULL;
	while (sprite_map == NULL)
		sprite_map = (t_sprite ***)malloc(mapsize * sizeof(void **));
	i = -1;
	while (++i < mapsize)
	{
		line_len = ft_strlen(map[i]);
		sprite_map[i] = NULL;
		while (sprite_map[i] == NULL)
			sprite_map[i] = (t_sprite **)malloc(line_len * sizeof(void *));
		j = -1;
		while (++j < line_len)
		{
			if (map[i][j] == '2')
				sprite_map [i][j] = create_sprite(i, j, '2');
			else
				sprite_map[i][j] = NULL;
		}
	}
	return (sprite_map);
}
