#include "cube3d.h"

int	create_mlx_image(t_data *data)
{
	data->img->img_ptr = mlx_new_image(data->mlx_ptr,
			data->win_width, data->win_height);
	if (data->img->img_ptr == NULL)
		return (-1);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	if (data->img->addr == NULL)
		return (-2);
	data->img->height = data->win_height;
	data->img->width = data->win_width;
	return (0);
}

int	start_mlx (t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_putstr_fd("failed to set up the connection (mlx_ptr == NULL)\n", 1);
		return (-1);
	}
	if (create_mlx_image(data) < 0)
	{
		ft_putstr_fd("mlx failed to create img\n", 1);
		return (-2);
	}
	return (0);
}
