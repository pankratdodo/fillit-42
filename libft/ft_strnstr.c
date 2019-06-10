/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:58:17 by plettie           #+#    #+#             */
/*   Updated: 2019/04/12 17:16:23 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hays, const char *need, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*lit;

	i = 0;
	j = 0;
	b = (char*)hays;
	lit = (char *)need;
	if (!lit[i])
		return (b);
	while (b[i] && (i < len))
	{
		while (b[i + j] == lit[j] && lit[j] && ((i + j) < len))
			j++;
		if (!lit[j])
			return (&b[i]);
		j = 0;
		i++;
	}
	return (0);
}
