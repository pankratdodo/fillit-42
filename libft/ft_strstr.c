/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:16:42 by plettie           #+#    #+#             */
/*   Updated: 2019/04/12 17:15:55 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*h;
	char	*n;

	i = 0;
	j = 0;
	h = (char*)haystack;
	n = (char *)needle;
	if (!n[i])
		return (h);
	while (h[i])
	{
		while (h[i + j] == n[j] && n[j])
			j++;
		if (!n[j])
			return (&h[i]);
		j = 0;
		i++;
	}
	return (0);
}
