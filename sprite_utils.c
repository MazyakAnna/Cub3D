#include "cube3d.h"

double	count_sq_dist(t_sprite *sprite, t_coords *coords)
{
	double	dy;
	double	dx;

	dx = sprite->x - coords->x;
	dy = sprite->y - coords->y;
	sprite->dist_sqr = dx * dx + dy * dy;
	return (dx * dx + dy * dy);
}

void	visible_sprites_add(t_sprite **visible_sprites,
		t_sprite *new, t_maze *maze)
{
	t_sprite	*tmp;

	if (visible_sprites == NULL || new == NULL)
		return ;
	new->dist_sqr = count_sq_dist(new, &maze->player->coords);
	if (*visible_sprites == NULL)
		*visible_sprites = new;
	else if ((*visible_sprites)->dist_sqr < new->dist_sqr)
	{
		new->next = *visible_sprites;
		*visible_sprites = new;
	}
	else
	{
		tmp = *visible_sprites;
		while (tmp->next != NULL && tmp->next->dist_sqr > new->dist_sqr)
			tmp = tmp->next;
		if (tmp->next != NULL && tmp->next->dist_sqr < new->dist_sqr)
		{
			new->next = tmp->next;
			tmp->next = new;
		}
		else
			tmp->next = new;
	}
}

void	draw_spritelist(t_data *data, t_sprite **sp)
{
	t_sprite	*tmp;
	int			i;

	i = 0;
	if (sp != NULL)
	{
		while (*sp != NULL)
		{
			draw_sprite(data, data->maze->player, *sp);
			data->maze->sprites_map[(*sp)->int_x][(*sp)->int_y]->visible = 1;
			if ((*sp)->next != NULL)
			{
				tmp = (*sp)->next;
				(*sp)->next = NULL;
				*sp = tmp;
			}
			else
				*sp = (*sp)->next;
		}
	}
}
