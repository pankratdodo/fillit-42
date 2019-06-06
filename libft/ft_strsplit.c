/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:37:51 by caellis           #+#    #+#             */
/*   Updated: 2019/05/04 17:12:27 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static int		ft_populate(char ***arr, const char *s, char c, size_t pos)
{
	long	rb;
	long	w_l;

	rb = 0;
	while (*s == c && *s)
	{
		rb++;
		s++;
	}
	w_l = ft_wordlen(s, c);
	if (((*arr)[pos] = ft_strnew(w_l)))
		ft_strncpy((*arr)[pos], s, w_l);
	else
		return (-1);
	return (rb + w_l);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		w_c;
	long		rb;
	size_t		i;

	split = NULL;
	if (s && c)
	{
		w_c = ft_countwords(s, c);
		if ((split = (char **)ft_memalloc(sizeof(char*) * (w_c + 1))))
		{
			i = 0;
			while (i < w_c)
			{
				if ((rb = ft_populate(&split, s, c, i)) < 0)
				{
					ft_freearray(&split, w_c);
					break ;
				}
				s += rb;
				i++;
			}
		}
	}
	return (split);
}
