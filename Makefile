NAME = cub3D

SRCS = 	get_resolution.c \
	 mlx_connection.c \
	 get_floor_ceilling.c \
	 get_sides.c check_map.c \
		get_sprite_texture.c \
		common_utils.c \
		player_moves.c \
		init_maze.c \
		precomputations.c \
		input_map_lists.c \
		print_inputs.c \
		launching.c \
		raycasting.c \
		display_errors.c \
		save_bmp.c \
		draw_2d.c \
		sprite_utils.c \
		draw_3d.c main.c \
		sprites_init.c \
		draw_sprites.c \
		map_parser.c \
		structs_initialization.c \
		drawing.c \
		free_everything.c \
		textures.c \
		get_next_line_utils.c \
		get_next_line.c

HDRS = cube3d.h \
	   defines.h \
	   structures.h

OBJS		= ${SRCS:.c=.o}

CC			= cc
RM			= rm -f

MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit

LIBFT_FLAGS	= -Llibft -lft

CFLAGS		= -Wall -Wextra	-Werror
INCLUDES	= -I mlx -I libft

all:	${NAME}

.c.o:
		${CC} ${INCLUDES} ${DEFINES} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS} ${OBJS_MLX}
		make -C libft
		${CC} ${OBJS} ${OBJS_MLX} ${LIBFT_FLAGS} ${MATH_FLAGS} ${MLX_FLAGS} -o ${NAME}

clean:
		make -C libft clean
		${RM} ${OBJS} ${OBJS_FULL} ${OBJS_MLX} ${OBJS_TERM}

fclean:	clean
		rm -f libft/libft.a
		${RM} ${NAME}

re:		fclean
	make all

.PHONY : all clean fclean re
