/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:07:34 by plettie           #+#    #+#             */
/*   Updated: 2019/04/14 11:48:46 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int				ft_atoi(const char *str)
{
	long long	n;
	int			c;

	c = 1;
	n = 0;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			c = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (c == -1 && (n != ((n * 10 + (*str - '0')) / 10)))
			return (0);
		else if (n != ((n * 10 + (*str - '0')) / 10))
			return (-1);
		n = n * 10 + *str - '0';
		str++;
	}
	return (n * c);
}
