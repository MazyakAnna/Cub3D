#ifndef CUBE3D_H
# define CUBE3D_H
//# include "libft/libft.h"
//# include "get_next_line/get_next_line.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "mlx.h"
# include "structures.h"
# include "defines.h"

int				count_chars (char *str, char c);
void			*freenull(void *ptr);
void			*freenulldouble(void **ptr);
void			fillarray(int *ptr, int size, int filler);
int				ft_strcmp(const char *s1, const char *s2);

int				check_cub_file(char *filepath, t_maze *maze, t_errors *errors);
int				get_resolution(char *line, t_maze *maze,
					int i, t_errors *errors);
int				is_empty_line(char *line, int i);
char			*ft_strncpy(char *dest, char *src, int n);

int				get_texture(char *line, int i, char **path, t_intcoords *size);
int				get_north(char *line, t_maze *maze, int i, t_errors *errors);
int				get_south(char *line, t_maze *maze, int i, t_errors *errors);
int				get_west(char *line, t_maze *maze, int i, t_errors *errors);
int				get_east(char *line, t_maze *maze, int i, t_errors *errors);
int				get_sprite(char *line, t_maze *maze, int i, t_errors *errors);

int				get_ceilling(char *line, t_maze *maze, int i, t_errors *errors);
int				get_floor(char *line, t_maze *maze, int i, t_errors *errors);

void			init_maze(t_maze *maze);
void			init_errors(t_errors *errors);
int				display_errors(t_errors *errors);

int				start_mlx (t_data *data);

int				check_flag(char *line, char *flag);
int				is_cub(char *line);
int				check_map(t_maze *maze);
void			print_map(char **coords);
void			print_params(t_maze *maze);

void			clear_maze(t_maze *maze);
void			maplist_to_map(t_maze *maze, t_list *head);
int				get_map(t_list **map_head, t_list **map_tail, char *line);
t_errors		input_data(t_maze *maze, int fd);

int				RGB_to_color(int *channels);
void			my_pixel_put(t_image *image, int x, int y, int color);
void			draw_line_DDA (int *A, int *B, t_image *image, int color);
void			draw_2d(t_data *data);
void			draw_txtr_column(t_image *image, t_txtr *txtr,
					t_intcoords *stripe, double coord);

int				move_Player(int key, t_data *data);
int				move_straight(t_player *player, char **map, double step_size);
int				move_sideways(t_player *player, char **map, double step_size);
int				turn_around(t_player *player, double rotation_angle);
void			precompute_invars(t_data *data);

t_coords		raycasting(t_coords *starting_point, t_coords *direction,
					t_data *data);
void			draw_first_person_view(t_data *data);

void			texture_to_image(void *mlx_ptr, t_image *img,
					char *filepath, t_intcoords *size);
unsigned int	get_color_from_image(t_image *img, int x, int y);
void			draw_sprt_txtr_column(t_image *image, t_txtr *txtr,
					t_intcoords *stripe, double coord);

void			fill_textures(t_data *data);

t_sprite		***create_sprites_map(char **map, size_t mapsize);
void			print_sprites_map(t_sprite ***sprites_map,
					int mapsize, char **map);
void			push_sprite_back(t_sprite **tail, t_sprite *sprite);
double			count_sq_dist(t_sprite *sprite, t_coords *coords);

void			draw_sprites(t_data *data, t_player *player, t_sprite **sprite);
void			draw_sprite(t_data *data, t_player *player, t_sprite *sprite);

void			add_sprite_sorted(t_sprite **head, t_sprite **item);
void			visible_sprites_add(t_sprite **visible_sprites,
					t_sprite *new, t_maze *maze);
void			draw_spritelist(t_data *data, t_sprite **head);
void			save_bmp(t_data *data);
int				close_game(t_data *data);
void			free_sprites(t_maze *maze);
void			break_free(t_data *data);

int				get_next_line(int fd, char **line);
int				ft_strchr_indx(char *buf, char c);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);

#endif
