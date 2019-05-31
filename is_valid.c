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
int kol_resh(char **line) //функция чекает количество # в каждой фигуре 
{
    size_t i;
    size_t j;
    size_t k;

    i = 0;
    j = 0;
    k = 0;
    while(line[i][j])
    {
        while (line[i][j] != '\n')
        {
            if (line[i][j] == '#')
                k++;
            i++;
        }
        if (line[0][j] == '\n')
        {
            if (k != 4)
                return (2);
            k = 0;
        }
        j++;
        i = 0;
    }
    return (0);
}

int nal_n(char **line) // функция чекает наличие \n после каждой фигуры и в середине
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (line[i][j])
    {
        if (line[4][j] != '\n' && line[0][j] != '\n')
            {write(1, "nal", 3);
                return (2);
            }
        j++;
    }
    return (0);
}

int len_n_hei(char **line) //функция чекает размер поля для каждой фигурки и количество фигур тоже
{
    size_t i;
    size_t j;
    size_t f; //количество фигур

    i = 0;
    j = 0;
    f = 0;
    while (line[i][j])
    {
        if (f > 26) // проверка по количеству
            return (2);
        if (line[i][j] == '\n' && j != 4 + 5 * f) // строка где \n но много строк было
            {write(1, "len1", 4);
                return (2);}
        if (line[i][j] == '\n' && j == 4 + 5 * f) // строка где \n и строк было норм
        {
            j++;
            f++;
        }
        while (line[i][j] == '.' || line[i][j] == '#')
            i++;
        if (i != 4) // много столбцов 
            {write(1, "len2", 4);
            return (2);}
        j++;
        i = 0;
    }
    return (0);
}

int touch(char **line) //чекает соседей #, если их нет, то ошибка
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (line[i][j])
    {
        while(line[i][j] != '\n')
        {
            if (line[i][j] == '#' && line[i - 1][j] != '#' && line[i + 1][j] != '#' && line[i][j - 1] != '#' && line[i][j + 1] != '#')
                {write(1, "tou", 3);
                return (2);}
            i++;
        }
        i = 0;
        j++;
    }
    return (0);
}

int is_valid(char **line) //основная функция
{
    int res;

    res = 0;
    if (((res = kol_resh(line)) == 2) || ((res = nal_n(line)) == 2) || ((res = len_n_hei(line)) == 2) || ((res = touch(line)) == 2))
        return (-1);
    else
        return (1);
}

