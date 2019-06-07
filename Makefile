# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:04:08 by caellis           #+#    #+#              #
#    Updated: 2019/06/07 13:31:23 by caellis          ###   ########.fr        #
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
	@$(CC) -g -o $@ $^ $(LIB)

%.o : %.c $(HEADERS)
	@$(CC) $(FLAGS) -g -c $(SOURCE) -I$(INCLUDE) $(LIB)

clean :
	@rm -rf $(wildcard *.o)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
