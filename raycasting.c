#include "cube3d.h"

double	get_step(double *step_x, double cos_x)
{
	double	step_dist;

	if (cos_x > 0)
	{
		*step_x = 1;
		step_dist = fabs(1 / cos_x);
	}
	else if (cos_x < 0)
	{
		*step_x = -1;
		step_dist = fabs(1 / cos_x);
	}
	else
	{
		*step_x = 0;
		step_dist = 1;
	}
	return (step_dist);
}

double	distance_to_grid(double starting_point, double step_dist, double cos_x)
{
	double	distance;

	if (cos_x >= 0)
		distance = (floor(starting_point) + 1.0 - starting_point) * step_dist;
	else
		distance = (starting_point - floor(starting_point)) * step_dist;
	return (distance);
}

int	process_intersection(t_maze *maze, t_intcoords cub,
			t_coords *distance, t_coords step_dist)
{
	int	collision;

	collision = 0;
	if (maze->map[cub.x][cub.y] == '1')
	{
		collision = 1;
		if (distance->x >= step_dist.x)
			distance->x -= step_dist.x;
		if (distance->y >= step_dist.y)
			distance->y -= step_dist.y;
	}
	else if (maze->map[cub.x][cub.y] == '2')
	{
		if (maze->sprites_map[cub.x][cub.y]->visible == 1)
		{
			count_sq_dist(maze->sprites_map[cub.x][cub.y],
				&maze->player->coords);
			visible_sprites_add(&maze->visible_sprites,
				maze->sprites_map[cub.x][cub.y], maze);
			(maze->sprites_map[cub.x][cub.y])->visible = 0;
			maze->vis_sprts++;
		}
	}
	return (collision);
}

void	DDA_loop(t_coords *distance, t_coords step_dist,
		t_coords step, t_maze *maze)
{
	int			collision;
	t_intcoords	cub;

	collision = 0;
	cub.x = floor(maze->player->coords.x);
	cub.y = floor(maze->player->coords.y);
	while (collision == 0)
	{
		if (distance->x < distance->y)
		{
			distance->x += step_dist.x;
			cub.x += step.x;
			distance->z = 0;
		}
		else
		{
			distance->y += step_dist.y;
			cub.y += step.y;
			distance->z = 1;
		}
		if (maze->map[cub.x][cub.y] != '0')
			collision = process_intersection(maze, cub, distance, step_dist);
	}
}

t_coords	raycasting(t_coords *starting_point,
		t_coords *direction, t_data *data)
{
	t_coords	step;
	t_coords	step_dist;
	t_coords	distance;
	t_coords	ret;

	step_dist.x = get_step(&step.x, direction->x);
	step_dist.y = get_step(&step.y, direction->y);
	distance.x = distance_to_grid(starting_point->x, step_dist.x, direction->x);
	distance.y = distance_to_grid(starting_point->y, step_dist.y, direction->y);
	DDA_loop(&distance, step_dist, step, data->maze);
	direction->z = distance.z;
	ret.z = distance.y;
	if (direction->z == 0 || direction->z == 4)
	{
		ret.z = distance.x;
		if (step.x < 0)
			direction->z += 2;
	}
	else if (step.y < 0)
		direction->z += 2;
	ret.x = (ret.z * direction->x + starting_point->x);
	ret.y = (ret.z * direction->y + starting_point->y);
	return (ret);
}
