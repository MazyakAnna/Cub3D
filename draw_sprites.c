#include "cube3d.h"

/*
** plane.x = player->direction.y * 0.6;
** plane.y = - player->direction.x * 0.6;
** invDet = 1.0 / (plane.x * player->direction.y
**						- player->direction.x * plane.y);
** invDet = 5.0 / 3.0;
** transform.x = invDet * (player->direction.y * sprite_dx
** 							- player->direction.x * sprite_dy);
** transform.y = invDet * (-plane.y * sprite_dx + plane.x * sprite_dy);
*/
t_coords	fix_distortion_coeff(t_player *player, t_sprite *sprite)
{
	double		sprite_dx;
	double		sprite_dy;
	t_coords	transform;

	sprite_dx = sprite->x - player->coords.x;
	sprite_dy = sprite->y - player->coords.y;
	transform.x = (player->direction.y * sprite_dx
			- player->direction.x * sprite_dy) * 5.0 / 3.0;
	transform.y = (player->direction.x * sprite_dx
			+ player->direction.y * sprite_dy);
	return (transform);
}

/*
** vert_line.y = размер отрисовываемых линий (то есть коэфициент размера спрайта)
** vert_line.x = текущая отрисовываемая линия спрайта
*/
void	draw_sprite(t_data *data, t_player *player, t_sprite *sprite)
{
	t_coords	transform;
	t_intcoords	vert_line;
	int			x_center;
	int			start_x;
	int			end_x;

	transform = fix_distortion_coeff(player, sprite);
	if (transform.y <= 0)
		return ;
	vert_line.y = fabs(round(data->win_width / (transform.y)));
	x_center = round((data->win_width / 2) * (1 + transform.x / transform.y));
	start_x = x_center - vert_line.y / 2;
	end_x = x_center + vert_line.y / 2;
	if (end_x >= data->win_width)
		end_x = data->win_width;
	vert_line.x = start_x;
	if (vert_line.x < 0)
		vert_line.x = 0;
	while (vert_line.x < end_x)
	{
		if (transform.y < data->z_buffer[vert_line.x])
			draw_sprt_txtr_column(data->img, data->maze->sprite,
				&vert_line, ((double)vert_line.x - start_x) / vert_line.y);
		vert_line.x++;
	}
}
