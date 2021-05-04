#include "cube3d.h"

void	draw_ray_3d(int side, t_data *data,
		t_intcoords *stripe, t_coords *rayend)
{
	if (side == 0)
		draw_txtr_column(data->img, data->maze->north, stripe, rayend->y);
	else if (side == 2)
		draw_txtr_column(data->img, data->maze->south, stripe, rayend->y);
	else if (side == 1)
		draw_txtr_column(data->img, data->maze->west, stripe, rayend->x);
	else if (side == 3)
		draw_txtr_column(data->img, data->maze->east, stripe, rayend->x);
	else if (side == 4 || side == 6 || side == 5 || side == 7)
		draw_txtr_column(data->img, data->maze->sprite, stripe, rayend->y);
}

void	draw_floor_ceil(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->win_height / 2)
	{
		j = 0;
		while (j < data->win_width)
		{
			my_pixel_put(data->img, i, j, data->maze->ceil_color);
			j++;
		}
		i++;
	}
	i = data->win_height / 2;
	while (i < data->win_height)
	{
		j = 0;
		while (j < data->win_width)
		{
			my_pixel_put(data->img, i, j, data->maze->floor_color);
			j++;
		}
		i++;
	}
}

/*
** dist *= cos_dists[x]; ->correction of distortion
*/
void	draw_walls(t_data *data, int x, t_coords *dir, int side)
{
	double		wallsize;
	t_coords	rayend;
	t_intcoords	stripe;

	dir->z = dir->x;
	dir->x = dir->x * data->invars.defl_cos
		- dir->y * data->invars.defl_sin * side;
	dir->y = dir->z * data->invars.defl_sin * side
		+ dir->y * data->invars.defl_cos;
	rayend = raycasting(&data->maze->player->coords, dir, data);
	stripe.x = data->win_width / 2 - x * side;
	rayend.z *= data->invars.cos_dists[x];
	data->z_buffer[data->win_width / 2 - x * side] = rayend.z;
	wallsize = data->invars.dist_to_viewplane * data->win_width / rayend.z;
	stripe.y = wallsize;
	draw_ray_3d((int)dir->z, data, &stripe, &rayend);
}

void	draw_first_person_view(t_data *data)
{
	int			x;
	t_coords	dir;
	t_coords	moondir;

	dir.x = data->maze->player->direction.x;
	dir.y = data->maze->player->direction.y;
	moondir.x = data->maze->player->direction.x;
	moondir.y = data->maze->player->direction.y;
	data->maze->player->ray_coords = raycasting(&data->maze->player->coords,
			&data->maze->player->direction, data);
	draw_floor_ceil(data);
	x = 0;
	while (x < data->win_width / 2)
		draw_walls(data, x++, &dir, 1);
	x = 0;
	while (x < data->win_width / 2)
		draw_walls(data, x++, &moondir, -1);
	draw_spritelist(data, &data->maze->visible_sprites);
	data->maze->visible_sprites = NULL;
}
