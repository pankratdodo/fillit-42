/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:32:11 by plettie           #+#    #+#             */
/*   Updated: 2019/04/14 11:50:43 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;
	unsigned char	coun;

	i = 0;
	coun = (unsigned char)c;
	src = (unsigned char *)s;
	while (n)
	{
		if (src[i] == coun)
			return (&src[i]);
		i++;
		n--;
	}
	return (0);
}
