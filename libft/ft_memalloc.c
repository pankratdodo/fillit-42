/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:53:27 by plettie           #+#    #+#             */
/*   Updated: 2019/04/09 13:32:53 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *str;

	str = (unsigned char*)malloc(size);
	if (!str)
		return (NULL);
	while (size)
	{
		size--;
		str[size] = 0;
	}
	return ((void*)str);
}
