# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 12:57:07 by ndelhota          #+#    #+#              #
#    Updated: 2025/04/23 09:06:35 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isspace3.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strcmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_vastrjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \

SRCBONUS =ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c

OBJ = $(SRC:.c=.o)

BONUSOBJ = $(SRCBONUS:.c=.o)

CC = clang

CFLAGS = -Werror -Wextra -Wall

NAME = libft.a

all : $(OBJ) $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus : $(OBJ) $(BONUSOBJ)
	ar rcs $(NAME) $?

clean :
	rm -f $(OBJ) //rm -f $(BONUSOBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
.SILENT:

