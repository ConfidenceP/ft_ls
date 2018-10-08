# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/31 09:34:55 by cmukwind          #+#    #+#              #
#    Updated: 2018/09/29 13:35:40 by cmukwind         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRC		= ls_funcs1.c \
		ls_funcs2.c \
	   	ls_funcs3.c \
		ls_funcs4.c \
		ls_funcs5.c \
	   	ls_funcs6.c \
		ls_funcs7.c \
		ls_funcs.c \
		main.c \
		sort_ls.c \
		g_var.c \

LIB		= libft/libft.a
LIBLS	= cmukwind/libftprintf.a

all: $(NAME)
$(NAME): $(LIB) $(LIBLS)
	gcc $(CFLAGS) $(SRC) $(LIB) $(LIBLS) -o $(NAME)
$(LIB):
	make -s -C ./libft

$(LIBLS):
	make -s -C ./cmukwind

clean:
	rm -f $(NAME)

fclean: clean
	make -C ./libft fclean
	make -C ./cmukwind fclean
re: fclean all

.PHONY: all, clean, fclean, re
