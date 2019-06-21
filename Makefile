# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <caellis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:04:08 by caellis           #+#    #+#              #
#    Updated: 2019/06/21 13:50:06 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := fillit

#FLAGS := -Wall -Wextra -Werror

INCLUDE := .
LIB := -L libft/ -lft

SOURCE := $(wildcard *.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCE))
HEADERS = $(wildcard *.c)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -g -o $@ $^ $(LIB)

%.o : %.c $(HEADERS)
	$(CC) $(FLAGS) -g -c $(SOURCE) -I$(INCLUDE) 

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
