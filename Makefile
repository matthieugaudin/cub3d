# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:08:53 by ndelhota          #+#    #+#              #
#    Updated: 2025/05/26 13:43:57 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

SRC := src/main.c \
       src/parsing/gen_map.c \
       src/parsing/get_map_intel.c \
       src/parsing/gen_map_error.c \
       src/parsing/intel_utils.c \
       src/parsing/get_map.c \
       src/parsing/check_colors.c \
       src/parsing/flood_fill.c \
       src/parsing/flood_errror.c \
       src/parsing/border_error.c \
       src/parsing/skip_space.c \
       src/parsing/ft_end.c \
       src/draw/init_texture.c \
       src/draw/handle_events.c \
       src/draw/keyboard_event.c \
       src/draw/mouse_event.c \
       src/draw/init_env.c \
       src/draw/minimap_init.c \
       src/draw/trim_texture.c \
       src/draw/put_pixel.c \
       src/draw/game_loop.c \
       src/draw/check_events.c \
       src/draw/handle_rotation.c \
       src/draw/draw_map.c \
       src/draw/draw_ray.c \

CC := cc

CFLAGS := -g -Wall -Werror -Wextra

OBJDIR = obj
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(OBJ))

LIB := lib/libft/libft.a \
       lib/gnl/gnl.a \
	lib/mlx_linux/libmlx.a \

all : $(LIB) $(OBJ) $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) \
		-Llib/mlx_linux -lmlx_Linux \
		-L/usr/lib -Ilib/mlx_linux \
		-lXext -lX11 -lm -lz -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c -o $@ $^

$(LIB) :
	@make bonus -C lib/libft
	@make -C lib/gnl
	@make -C lib/mlx_linux

clean :
	@rm -rf $(OBJDIR) 
	@make -C lib/libft clean
	@make -C lib/gnl clean
	@make -C lib/mlx_linux clean

fclean : clean 
	@rm -f $(NAME)
	@make -C lib/libft fclean
	@make -C lib/gnl clean

re : fclean all

.PHONY : all clean fclean re
