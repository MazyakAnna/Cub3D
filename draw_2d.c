#include "cube3d.h"

void	draw_square(t_image *image, t_intcoords coords, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			my_pixel_put(image, coords.x * size + i,
				coords.y * size + j++, color);
		i++;
	}
}

/*
void	draw_ray(t_data *data, double koef_2d)
{
	int			x;
	int			A[2];
	int			B[2];
	t_coords	dir;
	t_coords	moondir;
	t_coords	rayend;

	dir.x = data->maze->player->direction.x;
	dir.y = data->maze->player->direction.y;
	moondir.x = data->maze->player->direction.x;
	moondir.y = data->maze->player->direction.y;
	data->maze->player->ray_coords = raycasting(&data->maze->player->coords,
			&dir, data->maze->map, data);
	A[0] = round(data->maze->player->coords.x * koef_2d);
	A[1] = round(data->maze->player->coords.y * koef_2d);
	x = 0;
	while (x < data->win_width / 2)
	{
		dir.z = dir.x;
		dir.x = dir.x * data->invars.defl_cos - dir.y * data->invars.defl_sin;
		dir.y = dir.z * data->invars.defl_sin + dir.y * data->invars.defl_cos;
		rayend = raycasting(&data->maze->player->coords,
				&dir, data->maze->map, data);
		B[0] = round(rayend.x * koef_2d);
		B[1] = round(rayend.y * koef_2d);
		draw_line_DDA(A, B, data->img, 0x00A09000);
		moondir.z = moondir.x;
		moondir.x = moondir.x * data->invars.defl_cos
			- moondir.y * (-data->invars.defl_sin);
		moondir.y = moondir.z * (-data->invars.defl_sin)
			+ moondir.y * data->invars.defl_cos;
		rayend = raycasting(&data->maze->player->coords,
				&moondir, data->maze->map, data);
		B[0] = round(rayend.x * koef_2d);
		B[1] = round(rayend.y * koef_2d);
		draw_line_DDA(A, B, data->img, 0x00A09000);
		x++;
	}
}
*/

void	draw_player(t_data *data, double koef_2d)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = round(data->maze->player->coords.x * koef_2d);
	y0 = round(data->maze->player->coords.y * koef_2d);
	x1 = round(data->maze->player->direction.x * koef_2d);
	y1 = round(data->maze->player->direction.y * koef_2d);
	my_pixel_put(data->img, x0, y0, 0x0000FF00);
	my_pixel_put(data->img, x0 + x1, y0 + y1, 0x00FF0000);
}

void	draw_2dmap(t_maze *maze, t_data *data, double koef_2d)
{
	t_intcoords	coords;
	char		c;

	coords.x = 0;
	if (maze->map == NULL)
		return ;
	while (maze->map[coords.x] != NULL)
	{
		coords.y = 0;
		while (maze->map[coords.x][coords.y] != '\0')
		{
			c = maze->map[coords.x][coords.y];
			if (c == '1')
				draw_square(data->img, coords, koef_2d, 0x00FFFFFF);
			else if (c == '2')
				draw_square(data->img, coords, koef_2d, 0x000000FF);
			else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				maze->map[coords.x][coords.y] = '0';
			else if (c != '0')
				draw_square(data->img, coords, koef_2d, 0x00FF8800);
			coords.y++;
		}
		coords.x++;
	}
}

void	draw_2d(t_data *data)
{
	double	koef_2d;

	if (data->win_height > data->win_width)
		koef_2d = data->win_width / (8 * data->maze->mapsize);
	else
		koef_2d = data->win_height / (8 * data->maze->mapsize);
	draw_2dmap(data->maze, data, koef_2d);
	draw_player(data, koef_2d);
}
