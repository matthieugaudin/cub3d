# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 11:41:35 by ndelhota          #+#    #+#              #
#    Updated: 2025/04/23 09:21:50 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := gnl.a

SRC := get_next_line_utils.c \
       get_next_line.c \

OBJ := $(SRC:.c=.o)

CC := cc 

CFLAGS := -Wall -Wextra -Werror -g 

all : $(OBJ) $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean : 
	rm -f $(OBJ)

fclean : clean 
	rm -f $(NAME)

re : fclean all

.PHONY: name all re clean fclean
.SILENT:
