#include "cube3d.h"

/*
** MOVEMENT
** ] V - direction vector, its coordinates: {x(V); y(V)};
** => movement vector = V * step_size: {x(V) * step_size; y(V) * step_size};
** => {x'; y'} = {x0 + (x(V) * step_size); y0 + (y(V) * step_size)}.
** If step_size < 0, player goes backwards.
** if-blocks added to handle wall-collision.
*/
int	move_straight(t_player *player, char **map, double step_size)
{
	if (map[(int)(player->coords.x + player->direction.x * step_size)]
			[(int)(player->coords.y)] != '1')
		player->coords.x = player->coords.x
			+ player->direction.x * step_size;
	if (map[(int)(player->coords.x)]
			[(int)(player->coords.y + player->direction.y * step_size)] != '1')
		player->coords.y = player->coords.y + player->direction.y * step_size;
	return (1);
}

/*
** orthogonal vector to {x, y} = {-y, x} (rotated clock-wise);
** so it's just move_straight(), but with messed up directions and signs.
*/
int	move_sideways(t_player *player, char **map, double step_size)
{
	if (map[(int)(player->coords.x - player->direction.y * step_size)]
			[(int)(player->coords.y)] != '1')
		player->coords.x = player->coords.x - player->direction.y * step_size;
	if (map[(int)(player->coords.x)]
			[(int)(player->coords.y + player->direction.x * step_size)] != '1')
		player->coords.y = player->coords.y + player->direction.x * step_size;
	return (0);
}

/*
** ROTATION
** rotation matrix in 2-dimentional space (for clock-wise rotation): 
** [x'; y'] = [cos(a), -sin(a); sin(a), cos(a)] * [x; y];
** => x' = x * cos(a) - y * sin(a);
** y' = x * sin(a) + y * cos(a);
** considering that cos is even and sin is an odd function,
** it's enough to pass negative rotation_angle to turn counterclock-wise. 
*/
/*
int	turn_around(t_player *player, double rot_cos, double rot_sin)
{
	double	remembered_x;

	remembered_x = player->direction.x;
	player->direction.x = player->direction.x * rot_cos
		- player->direction.y * rot_sin;
	player->direction.y = remembered_x * rot_sin
		+ player->direction.y * rot_cos;
	return (0);
}
*/
int	turn_around(t_player *player, double rotation_angle)
{
	double	remembered_x;

	remembered_x = player->direction.x;
	player->direction.x = player->direction.x * cos(rotation_angle)
		- player->direction.y * sin(rotation_angle);
	player->direction.y = remembered_x * sin(rotation_angle)
		+ player->direction.y * cos(rotation_angle);
	return (0);
}

int	move_Player(int key, t_data *data)
{
	if (key == KEY_ESC)
		return (close_game(data));
	if (key == 13)
		move_straight(data->maze->player, data->maze->map, STEP_SIZE);
	else if (key == 1)
		move_straight(data->maze->player, data->maze->map, -STEP_SIZE);
	else if (key == KEY_ARR_L)
		turn_around(data->maze->player, ROTATION_ANGLE);
	else if (key == KEY_ARR_R)
		turn_around(data->maze->player, -ROTATION_ANGLE);
	else if (key == KEY_A)
		move_sideways(data->maze->player, data->maze->map, STEP_SIZE);
	else if (key == KEY_D)
		move_sideways(data->maze->player, data->maze->map, -STEP_SIZE);
	else
		printf ("Pressed key_code: %d\n", key);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr,
			data->win_width, data->win_height);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	draw_first_person_view(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	return (0);
}

int	close_game(t_data *data)
{
	break_free(data);
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
	return (1);
}
