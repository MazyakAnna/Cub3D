# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 15:56:21 by bmaegan           #+#    #+#              #
#    Updated: 2021/04/29 03:37:00 by bmaegan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a
CC =			gcc
CFLAGS =			-Wall -Wextra -Werror
RM =			rm -rf
AR =			ar rc
INCS =			-I $(HEADERS_PATH)
HEADERS_LIST =	libft.h
HEADERS_PATH =	./
HEADERS =		$(addprefix $(HEADERS_PATH), $(HEADERS_LIST))
SRCS_PATH =		./
B_SRCS_PATH =	./

SRCS_LIST =	ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strnstr.c\
			ft_strncmp.c\
			ft_atoi.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_calloc.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_lstnew.c\
		 	ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstmap.c\
			ft_lstiter.c\

SRCS =		$(addprefix $(SRCS_PATH), $(SRCS_LIST))
OBJS_PATH =	objects/
OBJS_LIST =	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS =		$(addprefix $(OBJS_PATH), $(OBJS_LIST))

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

bonus: $(OBJS_PATH) $(B_OBJS_PATH) $(OBJS) $(B_OBJS)
	@$(AR) $(NAME) $(OBJS) $(B_OBJS)
	@ranlib $(NAME)

$(B_OBJS_PATH):
	@mkdir -p $(B_OBJS_PATH)

$(B_OBJS_PATH)%.o : $(B_SRCS_PATH)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@$(RM) $(OBJS_PATH) $(B_OBJS_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
