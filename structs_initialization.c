#include "cube3d.h"

void	init_intcoords(t_intcoords *coord)
{
	coord->x = 0;
	coord->y = 0;
	coord->z = 0;
}

void	init_coords(t_coords *coord)
{
	coord->x = 0;
	coord->y = 0;
	coord->z = 0;
}

void	init_errors(t_errors *errors)
{
	errors->R = 1;
	errors->NO = 1;
	errors->SO = 1;
	errors->WE = 1;
	errors->EA = 1;
	errors->S = 1;
	errors->F = 1;
	errors->C = 1;
	errors->map = 1;
	errors->others = 0;
}
