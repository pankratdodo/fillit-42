# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <caellis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 14:05:14 by caellis           #+#    #+#              #
#    Updated: 2019/06/07 14:07:45 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/sh

# Запусти скрипт, и он сгенерирует карту и запустит филлит вместе с ней 
# (а также засечет и покажет время)

make -C libft/ re ; make clean
make re ; make clean
python3 development_/rand_test.py > curr_test
echo "THIS IS YOUR TEST\n==>\n" && cat curr_test
echo "\nand THIS IS YOU FILLIT OUTPUT\n==>\n" && time ./fillit curr_test
rm -rf curr_test
