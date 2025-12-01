# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/23 14:57:52 by jdreissi          #+#    #+#              #
#    Updated: 2025/12/01 16:14:36 by jdreissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

CC = cc

C_FLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

SRC =	ft_printf.c \
		ft_convert.c \
		ft_convert_2.c \
		ft_printf_helper.c \
		ft_memset.c \
		ft_strlen.c

O_FILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES) $(HEADER)
	ar -rcs $(NAME) $(O_FILES)

%.o: %.c $(HEADER)
	$(CC)  -c $< -o $@

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
