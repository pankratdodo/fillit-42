# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:04:08 by caellis           #+#    #+#              #
#    Updated: 2019/07/23 22:13:58 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := fillit

FLAGS := -Wall -Wextra -Werror

LIB := ./libft/libft.a

SOURCE := $(wildcard *.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCE))

all: $(NAME)

$(OBJECTS): %.o : %.c
	@$(CC) $(FLAGS) -c $(SOURCE)

$(LIB):
	@make -C libft/

$(NAME): $(OBJECTS) $(LIB)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $(NAME)

clean :
	@rm -rf $(OBJECTS)
	@make -C libft/ clean

fclean : clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

re : fclean all
