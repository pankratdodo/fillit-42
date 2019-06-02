/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:58:48 by plettie           #+#    #+#             */
/*   Updated: 2019/05/29 16:58:50 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft/libft.h"

int len_all(char **line) //подстчет количества строк и проверка на валидность по количеству
{
    size_t i;
    size_t j;
    size_t k;

    i = 0;
    j = 0;
    k = 0; // количество фигур
    while (line[i][j])
    {
        if ((j % (4 + 5 * k) == 0 && line[i][j]) || k > 26) //проверка на количество строк в каждой фигурке и количество фигурок
            return (-1);
        else if (j % (4 + 5 * k) == 0 && !line[i][j])
            k++;
        j++;
    }
    return (j);
}

int kol_resh(char **line, int k) //функция чекает количество # в каждой фигуре и количество столбцов
{
    size_t i;
    size_t j;
    size_t resh;

    i = 0;
    j = 0;
    resh = 0;
    while (k)
    {
        while (i < 4 && j % 4 != 0)
        {
            if (line[i][j] == '#')
                resh++;
            i++;
        }
        if (!line[0][j]) //когда в строке только /n
        {
            if (resh != 4)
                return (2);
            resh = 0;
        }
        if (line[4][j]) // не много ли столбцов в фигурке
            return (2);
        j++;
        i = 0;
        k--;
    }
    return (0);
}

int nal_n(char **line, int k) // функция чекает наличие \n после каждой фигуры и в середине
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (k)
    {
        if (line[4][j] && line[0][j])
            return (2);
        j++;
        k--;
    }
    return (0);
}

int touch(char **line, int k) //чекает соседей #, если их нет, то ошибка
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (k)
    {
        while(line[i][j])
        {
            if (line[i][j] == '#' && line[i - 1][j] != '#' && line[i + 1][j] != '#' && line[i][j - 1] != '#' && line[i][j + 1] != '#')
                return (2);
            i++;
        }
        i = 0;
        j++;
        k--;
    }
    return (0);
}

int is_valid(char **line) //основная функция
{
    int res;
    int k;

    res = 0;
    if ((k = len_all(line)) < 0)
        return (-1);
    if (((res = kol_resh(line, k)) == 2) || ((res = nal_n(line, k)) == 2) || ((res = touch(line, k)) == 2))
        return (-1);
    else
        return (1);
}

