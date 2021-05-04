#include "cube3d.h"

void	bmp_header(t_data *data, int size, int fd)
{
	unsigned char	header[54];

	ft_bzero(header, 54);
	header[0] = 'B';
	header[1] = 'M';
	ft_memcpy(&header[2], &size, 4);
	header[10] = 54;
	header[0 + 14] = 40;
	ft_memcpy(&header[4 + 14], &data->win_width, 4);
	ft_memcpy(&header[8 + 14], &data->win_height, 4);
	header[12 + 14] = 1;
	header[14 + 14] = 32;
	write(fd, header, 54);
}

void	save_bmp(t_data *data)
{
	int	fd;
	int	line_size;
	int	y;

	fd = open("scrshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	line_size = data->win_width * data->img->bpp / 8;
	bmp_header(data, line_size * data->win_height, fd);
	y = data->win_height;
	while (y >= 0)
	{
		write(fd, (unsigned char *)(data->img->addr
				+ y * data->img->line_len), line_size);
		y--;
	}
	close(fd);
}
