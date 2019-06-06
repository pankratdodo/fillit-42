/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:09:49 by caellis           #+#    #+#             */
/*   Updated: 2019/06/06 13:16:15 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/is_valid.h"

int         main(int ac, char **av)
{
    int fd;
    char c;

    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open("test.txt", O_RDONLY);
    if (is_valid(fd))
        write(1, "harosh", 6);              // И здесь идет map2tetris
    else
        write(1, "sore ne valid", 13);      // Или еррор :(
    return (0);
}