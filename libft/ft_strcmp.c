/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:02:56 by plettie           #+#    #+#             */
/*   Updated: 2019/02/05 18:22:29 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *str;
	unsigned char *src;

	str = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (*str == *src && *str)
	{
		str++;
		src++;
	}
	return (*str - *src);
}
