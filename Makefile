# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 15:28:03 by nmaazouz          #+#    #+#              #
#    Updated: 2022/11/22 21:15:36 by nmaazouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc 
FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
SRC = lib_print.c ft_printf.c
OBJ = $(SRC:%.c=%.o)
 
all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ)
	$(AR) $@ $^

clean: 
	$(RM) $(OBJ)

fclean: 
	$(RM) $(NAME) $(OBJ)

re: fclean $(NAME)