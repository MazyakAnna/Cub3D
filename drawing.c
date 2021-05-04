#include "cube3d.h"

/*
** (* 256) == (<< 8)
*/
int	RGB_to_color(int *channels)
{
	int	i;

	i = 0;
	i = channels[0] * 256 + channels[1];
	i = i * 256 + channels[2];
	return (i);
}

void	my_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (x * image->line_len + y * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_txtr_column(t_image *image, t_txtr *txtr,
		t_intcoords *stripe, double coord)
{
	int		y;
	int		i;
	double	shift;
	int		color;

	i = 0;
	shift = 0;
	coord = fabs(coord - floor(coord));
	while ((i < (stripe->y / 2)) && (i < (image->height / 2)))
	{
		y = image->height / 2 - i;
		color = get_color_from_image(txtr->img, (txtr->size.x * coord),
				(txtr->size.y / 2 - (int)shift + 1));
		my_pixel_put(image, y, stripe->x, color);
		y = image->height / 2 + i;
		color = get_color_from_image(txtr->img, (txtr->size.x * coord),
				(txtr->size.y / 2 + (int)shift - 1));
		my_pixel_put(image, y, stripe->x, color);
		shift += (double)txtr->size.y / (double)stripe->y;
		i++;
	}
}

void	draw_sprt_txtr_column(t_image *image, t_txtr *txtr,
		t_intcoords *stripe, double coord)
{
	int		y;
	int		i;
	double	shift;
	int		color;

	i = 0;
	shift = 0;
	coord = fabs(coord - floor(coord));
	while ((i < (stripe->y / 2)) && (i < (image->height / 2)))
	{
		y = image->height / 2 - i;
		color = get_color_from_image(txtr->img, (txtr->size.x * coord),
				(txtr->size.y / 2 - (int)shift + 1));
		if (color > 0)
			my_pixel_put(image, y, stripe->x, color);
		y = image->height / 2 + i;
		color = get_color_from_image(txtr->img, (txtr->size.x * coord),
				(txtr->size.y / 2 + (int)shift - 1));
		if (color > 0)
			my_pixel_put(image, y, stripe->x, color);
		shift += (double)txtr->size.y / (double)stripe->y;
		i++;
	}
}

void	draw_line_DDA (int *A, int *B, t_image *image, int color)
{
	t_intcoords	offset;
	t_coords	incr;
	t_coords	coord;
	int			steps;
	int			i;

	offset.x = B[0] - A[0];
	offset.y = B[1] - A[1];
	if (abs(offset.x) > abs(offset.y))
		steps = abs(offset.x);
	else
		steps = abs(offset.y);
	incr.x = offset.x / (float)steps;
	incr.y = offset.y / (float)steps;
	coord.x = A[0];
	coord.y = A[1];
	i = 0;
	while (i <= steps)
	{
		my_pixel_put(image, round(coord.x), round(coord.y), color);
		coord.x += incr.x;
		coord.y += incr.y;
		i++;
	}
}
