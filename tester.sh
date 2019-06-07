# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <caellis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 14:05:14 by caellis           #+#    #+#              #
#    Updated: 2019/06/07 15:17:31 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/sh

# Запусти скрипт, и он сгенерирует карту и запустит филлит вместе с ней 
# (а также засечет и покажет время)
# советую перед запуском ебануть => $ alias testme="sh tester.sh"  тогда можно будет еще меньше писать:)

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

# TESTING 0 and 2 arguments
echo "\nTHIS IS TO CHECK 0 & 2 inputs\n==>\n"
echo "0 arguments:\n"$RED
./fillit
echo $NC"\n2 arguments:\n"$RED
./fillit development_/input/valid/valid_00 development_/input/valid/valid_01
echo $NC
read -n 1 -s -r -p "Press any key to continue"

# TESTING ERRORS
echo "\nSTARTING ERROR TESTING\n==>\n"
for n in $ERROR;
do
	echo "Error test $RED[$i]$NC:\n"
	echo "$BLUE[Input]$NC\n"
	cat $n
	echo "\n$BLUE[Output]$NC\n"$RED
	time ./fillit $n
	(( i++ ))
	echo $NC
	read -n 1 -s -r -p "Press any key to continue"
done

# TESTING OK INPUT - works or not (not right or wrong)
for ((i = 0; i < 3; i++))
do 
	python3 development_/rand_test.py > curr_test ;
	echo "\nTHIS IS $BLUE CURRENT VALID TEST $NC \n==>\n" && cat curr_test
	echo "\nand THIS IS $BLUE YOUR FILLIT OUTPUT $NC \n==>\n$RED" && time ./fillit curr_test
	echo $NC
	read -n 1 -s -r -p "Press any key to continue"
done

rm -rf curr_test
