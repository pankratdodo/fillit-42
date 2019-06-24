# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <caellis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:04:08 by caellis           #+#    #+#              #
#    Updated: 2019/06/24 14:43:39 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := libft.a

FLAGS := -Wall -Wextra -Werror

INCLUDE := .

SOURCE = $(wildcard ft_*.c)

OBJECTS = $(patsubst %.c,%.o,$(SOURCE))

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)

%.o : %.c libft.h
	@$(CC) -c $(FLAGS) $(SOURCE) -I$(INCLUDE)

clean :
	@rm -rf $(wildcard ft_*.o)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
