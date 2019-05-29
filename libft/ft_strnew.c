/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:44:07 by plettie           #+#    #+#             */
/*   Updated: 2019/04/17 11:49:48 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if ((size + 1) == 0)
		return (0);
	if (!(str = (char *)malloc((size + 1) * sizeof(*str))))
		return (NULL);
	while (size + 1)
	{
		str[size] = '\0';
		size--;
	}
	return (str);
}
