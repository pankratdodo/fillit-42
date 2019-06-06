# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:04:08 by caellis           #+#    #+#              #
#    Updated: 2019/06/06 20:03:57 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := fillit

#FLAGS := -Wall -Wextra -Werror

INCLUDE := .
LIB := -L libft/ -lft

SOURCE = $(wildcard *.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCE))
HEADERS = $(patsubst %.c,%.h,$(SOURCE))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) -o $@ $^ $(LIB)

%.o : %.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(SOURCE) -I$(INCLUDE) $(LIB)

clean :
	@rm -rf $(wildcard *.o)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
