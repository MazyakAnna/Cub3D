#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_errors
{
	int			R;
	int			NO;
	int			SO;
	int			WE;
	int			EA;
	int			S;
	int			F;
	int			C;
	int			map;
	int			others;
}				t_errors;

typedef struct s_coords
{
	double		x;
	double		y;
	double		z;
}				t_coords;

typedef struct s_intcoords
{
	int			x;
	int			y;
	int			z;
}				t_intcoords;

typedef struct s_image
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_txtr
{
	char		*path;
	t_intcoords	size;
	t_image		*img;
}				t_txtr;

typedef struct s_player
{
	t_coords	coords;
	t_coords	direction;
	t_coords	ray_coords;
}				t_player;

typedef struct s_sprite
{
	double			x;
	double			y;
	double			dist_sqr;
	char			type;
	int				int_x;
	int				int_y;
	int				visible;
	struct s_sprite	*next;
}					t_sprite;

typedef struct s_maze
{
	int			resolution[2];
	t_txtr		*north;
	t_txtr		*south;
	t_txtr		*west;
	t_txtr		*east;
	t_txtr		*sprite;
	int			floor[3];
	int			ceilling[3];
	int			floor_color;
	int			ceil_color;
	size_t		mapsize;
	t_list		*map_list;
	t_list		*map_tail;
	char		**map;
	t_player	*player;
	int			sprites_num;
	t_sprite	***sprites_map;
	t_sprite	*visible_sprites;
	int			vis_sprts;
}				t_maze;

/*
** invariants, precomputed values.
** rot sin/cos -- for rotation angle;
** defl sin/cos -- for the angle side rays deflect from the main and each other
** cos_dists -- table of precomputed cos 
** for every (angle = 2x/winwidth) to fix distortion
**                    and find "normalized" distance
*/
typedef struct s_invars
{
	double		dist_to_viewplane;
	double		rot_sin;
	double		rot_cos;
	double		defl_sin;
	double		defl_cos;
	double		*cos_dists;
}				t_invars;

typedef struct s_data
{
	t_maze		*maze;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img;
	int			win_width;
	int			win_height;
	t_invars	invars;
	double		*z_buffer;
}				t_data;

#endif