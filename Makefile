# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/23 14:57:52 by jdreissi          #+#    #+#              #
#    Updated: 2025/10/25 11:13:59 by jdreissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

CC = cc

C_FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRC =	ft_printf.c \
		tostring.c \
		fill_parse_list.c

O_FILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES) $(HEADER)
	ar -rcs  $(NAME) $(O_FILES)

%.o: %.c $(HEADER)
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
