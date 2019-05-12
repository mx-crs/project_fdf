#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 11:53:17 by myarovoy          #+#    #+#              #
#    Updated: 2018/06/08 11:53:18 by myarovoy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
LIBRARY = fdflibft.a

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I includes/
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

FILES = main.c \
		bresenham.c \
		get_coordinates.c \
		key_functions1.c \
		key_functions2.c \
		valid_init.c \
		get_fdf.c

LIBFILES =	ft_memmove.c	\
			ft_memcpy.c		\
			ft_strlen.c		\
			ft_strdup.c		\
			ft_isdigit.c	\
			ft_strcpy.c		\
			ft_strncpy.c	\
			ft_strcat.c		\
			ft_strncat.c	\
			ft_strchr.c		\
			ft_strcmp.c		\
			ft_atoi.c		\
			ft_memalloc.c	\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strsplit.c	\
			ft_putstr.c		\
			ft_putnbr.c		\
			ft_cnt_words.c	\
			get_next_line.c

.PHONY = all clean fclean re

FDFSRCS	= $(addprefix src/, $(FILES))
LIBSRCS	= $(addprefix src/libft/, $(LIBFILES))

OBJ = $(FDFSRCS:.c=.o)
LIBOBJ = $(LIBSRCS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBOBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBRARY): $(LIBOBJ)
	@ar rcs $(LIBRARY) $(LIBOBJ)

$(NAME): $(LIBRARY) $(OBJ)
	@gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LIBRARY) $(MLXFLAGS)
	@echo "\033[32mCreated Executable ./fdf\033[0m"

clean:
	@rm -rf $(OBJ) $(LIBOBJ)
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBRARY)
	@echo "\033[32mRemoved Executable and library\033[0m"

re: fclean all
