# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:04:08 by caellis           #+#    #+#              #
#    Updated: 2019/05/04 16:09:47 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := libft.a

FLAGS := -Wall -Wextra -Werror

NAME := libft.a

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
	@rm -rf $(TEST) test_func.o

re : fclean all
