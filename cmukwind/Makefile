# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 10:43:42 by cmukwind          #+#    #+#              #
#    Updated: 2018/08/25 15:33:05 by cmukwind         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libftprintf.a
CC=		gcc
CFLAGS=	-Wall -Werror -Wextra
SRC=	ft_printf.c ls_putnbr.c ls_putnbr_base.c ft_put_unbr_base.c\
    	ls_putstr.c ls_strlen.c funcs1.c funcs2.c funcs3.c funcs4.c funcs5.c\
		funcs6.c ls_putchar.c ls_atoi.c ls_strdup.c ft_putwstr.c ft_putwchar.c\
		ft_putwnbr.c ft_putwnbr_base.c ft_put_wunbr_base.c ft_uputnbr.c\
		ls_itoa_base.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
