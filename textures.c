#include "cube3d.h"

void	texture_to_image(void *mlx_ptr, t_image *img,
			char *filepath, t_intcoords *size)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filepath, &size->x, &size->y);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
}

unsigned int	get_color_from_image(t_image *img, int x, int y)
{
	char			*img_color;
	unsigned int	color;

	img_color = img->addr + y * img->line_len + x * img->bpp / 8;
	color = *(unsigned *)img_color;
	return (color);
}

void	fill_txtr(t_txtr *txtr, t_data *data)
{
	texture_to_image(data->mlx_ptr, txtr->img,
		txtr->path, &txtr->size);
}

void	fill_textures(t_data *data)
{
	fill_txtr(data->maze->north, data);
	fill_txtr(data->maze->south, data);
	fill_txtr(data->maze->west, data);
	fill_txtr(data->maze->east, data);
	fill_txtr(data->maze->sprite, data);
}
