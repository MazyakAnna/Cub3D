#include "cube3d.h"

int	parse_and_check(t_maze *maze, char *filepath)
{
	t_errors	errors;
	int			i;

	i = 0;
	init_maze(maze);
	if (check_cub_file(filepath, maze, &errors) == 0)
	{
		i = display_errors(&errors);
	}
	else
		return (-1);
	return (i);
}

void	game_loop(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, move_Player, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_game, data);
	mlx_loop(data->mlx_ptr);
}

void	start_game(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "Cub3D");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	game_loop(data);
}

int	start_cube(t_maze *maze, int mode)
{
	t_data	data;
	t_image	image;

	data.img = &image;
	data.maze = maze;
	precompute_invars(&data);
	data.win_width = data.maze->resolution[0];
	data.win_height = data.maze->resolution[1];
	data.z_buffer = (double *)malloc(data.win_width * sizeof(double));
	start_mlx (&data);
	fill_textures(&data);
	maze->sprites_map = create_sprites_map(maze->map, maze->mapsize);
	draw_first_person_view(&data);
	if (mode == 0)
		start_game(&data);
	else
	{
		save_bmp(&data);
		break_free(&data);
	}
	return (0);
}

/*
** clear_maze -> to add;
*/
int	main(int argc, char **argv)
{
	t_maze	maze;

	if (argc == 2 && is_cub(argv[1]))
	{
		if (parse_and_check(&maze, argv[1]) == 0)
			start_cube(&maze, 0);
	}
	else if (argc == 3 && is_cub(argv[1])
		&& (check_flag(argv[2], "--save")))
	{
		if (parse_and_check(&maze, argv[1]) == 0)
			start_cube(&maze, 1);
	}
	else
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Проверьте правильность вводимых аргументов\n", 1);
	}
	return (0);
}
