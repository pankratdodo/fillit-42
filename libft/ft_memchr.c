/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 10:14:47 by caellis           #+#    #+#             */
/*   Updated: 2019/04/10 16:44:37 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	unsigned char	waldo;

	buff = (unsigned char *)s;
	waldo = (unsigned char)c;
	while (n--)
	{
		if (*buff == waldo)
			return (buff);
		buff++;
	}
	return (NULL);
}
