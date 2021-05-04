#include "cube3d.h"

int	display_error_R(int error)
{
	if (error == 0)
		return (0);
	ft_putstr_fd("Error\n", 1);
	if (error == 1)
		ft_putstr_fd("No resolution (R) in file\n", 1);
	else if (error == 2)
		ft_putstr_fd("There is more than one line with R in the beginning\n", 1);
	else if (error == 3)
		ft_putstr_fd("Check if the first argument for R is a number!\n", 1);
	else if (error == 4)
		ft_putstr_fd("Check if the 2nd argument for R is a number!\n", 1);
	else if (error == 5)
		ft_putstr_fd("More than 2 arguments for R\n", 1);
	else if (error > 999)
		ft_putstr_fd("Error during malloc! Oooooooops!\n", 1);
	else if (error == 6)
		ft_putstr_fd("Something wrong with resolution params\n", 1);
	return (error);
}

int	display_error_texture(int error, char *texture_dest)
{
	if (error == 0)
		return (0);
	ft_putstr_fd("Error\n", 1);
	if (error == 1)
		ft_putstr_fd("There is no identificator in your .cub file for ", 1);
	else if (error == 2)
		ft_putstr_fd("More than one identificator in .cub file for ", 1);
	else if (error == 3)
		ft_putstr_fd("Lol. You've forgotten to input path for ", 1);
	else if (error == 4)
		ft_putstr_fd("There's too many arguments for ", 1);
	else if (error == 5)
		ft_putstr_fd("Your path to texture is wrong for ", 1);
	ft_putstr_fd(texture_dest, 1);
	write(1, "!\n", 2);
	return (error);
}

int	display_error_color(int error, char *color_dest)
{
	if (error == 0)
		return (0);
	ft_putstr_fd("Error\n", 1);
	if (error == 1)
		ft_putstr_fd("There is no identificator in your .cub file for ", 1);
	else if (error == 2)
		ft_putstr_fd("More than one identificator in .cub file for ", 1);
	else if (error == 3)
		ft_putstr_fd("Lol. You've forgotten to input color for ", 1);
	else if (error == 4)
		ft_putstr_fd("Too many arguments or extra chars in color for ", 1);
	else if (error == 5)
		ft_putstr_fd("Your color input is wrong for ", 1);
	ft_putstr_fd(color_dest, 1);
	write(1, "!\n", 2);
	return (error);
}

int	display_error_map(int error)
{
	if (error == 0)
		return (0);
	ft_putstr_fd("Error\n", 1);
	if (error == 1)
		ft_putstr_fd("NO MAP!\n", 1);
	else if (error == 2)
		ft_putstr_fd("ZERO NEAR EMTY SPACE IN MAP!\n", 1);
	else if (error == 3)
		ft_putstr_fd("Hole or wrong symbol in the left mapwall\n", 1);
	else if (error == 4)
	{
		ft_putstr_fd("Hole or invalid symbol ", 1);
		ft_putstr_fd("in the first or the last line of the map!\n", 1);
	}
	else if (error == 5)
		ft_putstr_fd("No player on the map!\n", 1);
	else if (error == 6)
		ft_putstr_fd("More than one player on the map!\n", 1);
	else if (error == 7)
		ft_putstr_fd("Player borders with empty space!\n", 1);
	else if (error == 8)
		ft_putstr_fd("Invalid symbol in the map!\n", 1);
	else
		ft_putstr_fd("Unknown map error!\n", 1);
	return (error);
}

int	display_errors(t_errors *errors)
{
	int	check;

	if (errors->others != 0)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("One of the lines doesn't match any identificator!\n", 1);
		ft_putstr_fd("Only R, NO, SO, WE, EA, S, F, C, 1, 2 (and spaces)\n", 1);
		ft_putstr_fd("are allowed in the beginning of a line!\n", 1);
		return (-1);
	}
	check = display_error_R(errors->R);
	check += display_error_texture(errors->NO, "NOrth");
	check += display_error_texture(errors->SO, "SOuth");
	check += display_error_texture(errors->WE, "WEst");
	check += display_error_texture(errors->EA, "EAst");
	check += display_error_texture(errors->S, "Sprite");
	check += display_error_color(errors->F, "Floor");
	check += display_error_color(errors->C, "Ceilling");
	check += display_error_map(errors->map);
	return (check);
}
