#include "cube3d.h"

t_sprite	*create_sprite(int i, int j, char c)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	sprite->x = i + 0.5;
	sprite->y = j + 0.5;
	sprite->int_x = i;
	sprite->int_y = j;
	sprite->type = c;
	sprite->visible = 1;
	return (sprite);
}

t_sprite	***create_sprites_map(char **map, int mapsize)
{
	t_sprite	***sprite_map;
	int			i;
	int			j;
	size_t		line_len;

	i = 0;
	sprite_map = (t_sprite ***)malloc(mapsize * sizeof(void **));
	while (i < mapsize)
	{
		j = 0;
		line_len = ft_strlen(map[i]);
		sprite_map[i] = (t_sprite **)malloc(line_len * sizeof(void *));
		while (j < line_len)
		{
			if (map[i][j] == '2')
				sprite_map [i][j] = create_sprite(i, j, '2');
			else
				sprite_map[i][j] = NULL;
			j++;
		}
		i++;
	}
	return (sprite_map);
}
