# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:08:53 by ndelhota          #+#    #+#              #
#    Updated: 2025/04/30 12:37:01 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := CUB3d 

SRC := main.c \
       gen_map/gen_map.c \
       gen_map/get_map_intel.c \
       gen_map/gen_map_error.c \
       gen_map/intel_utils.c \
       gen_map/get_map.c \
       gen_map/flood_fill.c \
       gen_map/flood_errror.c \
       gen_map/border_error.c \
       graphic_init/ft_graphic.c \
       end/ft_end.c \
       #ray_casting.c \

CC := cc

CFLAGS := -g -Wall -Werror -Wextra

OBJDIR = obj
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(OBJ))

LIB := lib/libft/libft.a \
       lib/gnl/gnl.a \
	   mlx_linux/libmlx.a \

all : $(LIB) $(OBJ) $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -lm

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c -o $@ $^

$(LIB) :
	@make bonus -C lib/libft
	@make -C lib/gnl
	@make -C mlx_linux

clean :
	@rm -rf $(OBJDIR) 
	@make -C lib/libft clean
	@make -C lib/gnl clean
	@make -C mlx_linux clean

fclean : clean 
	@rm -f $(NAME)
	@make -C lib/libft fclean
	@make -C lib/gnl clean

re : fclean all

.PHONY : all clean fclean re
