/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:48:01 by plettie           #+#    #+#             */
/*   Updated: 2019/04/14 11:55:40 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *str, const char *src, size_t n)
{
	size_t l;
	size_t len;

	l = 0;
	len = 0;
	while (*str)
	{
		l++;
		str++;
	}
	while (src[len])
		++len;
	if (n <= l)
		len += n;
	else
		len += l;
	while (*src && l + 1 < n)
	{
		*str++ = *src++;
		l++;
	}
	*str = '\0';
	return (len);
}
