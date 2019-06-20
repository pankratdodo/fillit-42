# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_map2tetris.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <caellis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 14:05:14 by caellis           #+#    #+#              #
#    Updated: 2019/06/20 15:57:24 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/sh

# COLORS
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0;m'

# MAKING
make -C libft/ re ; make clean
make re ; make clean

# Input test-files location
ERROR=development_/test/input/error/*
VALID=development_/test/input/valid/*

# TESTING HOW FIGURES is being filled 
for ((i = 0; i < 3; i++))
do 
	python3 development_/rand_test.py > curr_test
	NUM_FIG=$(awk 'BEGIN	{i = 0}
				{if (length($0) != 0)
			   		i++}
		 END	{print i/4}' curr_test)
	echo "\nTHIS IS $BLUE CURRENT VALID TEST $NC \n==>\n" && cat curr_test
	echo "\nTHIS IS $BLUE THE NUMBER OF FIGURES $NC \n==>\n$GREEN $NUM_FIG $NC \n"
	echo "\nand THIS IS $BLUE YOUR FIGURES list $NC \n==>\n$RED" && ./fillit curr_test
	echo $NC
	read -n 1 -s -r -p "Press any key to continue"
done

rm -rf curr_test
