#include "cube3d.h"

void	precompute_invars(t_data *data)
{
	int	x;

	data->win_width = data->maze->resolution[0];
	data->win_height = data->maze->resolution[1];
	data->invars.rot_sin = sin(ROTATION_ANGLE);
	data->invars.rot_cos = cos(ROTATION_ANGLE);
	data->invars.dist_to_viewplane = 1.0 / (2 * tan((FOV / 2) * M_PI / 180));
	printf("dist_to_view: %f\n", data->invars.dist_to_viewplane);
	data->invars.defl_cos = cos((FOV * M_PI) / (data->win_width * 180));
	data->invars.defl_sin = sin((FOV * M_PI) / (data->win_width * 180));
	data->invars.cos_dists = (double *)malloc((data->win_width / 2)
			* sizeof(double));
	x = 0;
	while (x < data->win_width / 2)
	{
		data->invars.cos_dists[x] = cos((x * FOV * M_PI)
				/ (data->win_width * 180));
		x++;
	}
}
