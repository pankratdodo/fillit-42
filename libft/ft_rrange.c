/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:53:09 by plettie           #+#    #+#             */
/*   Updated: 2019/04/17 11:50:18 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_rrange(int start, int end)
{
	int n;
	int k;
	int i;
	int *mas;

	k = 0;
	i = 0;
	n = start + 1;
	while (n <= end)
	{
		n++;
		k++;
	}
	mas = (int*)malloc(k + 1);
	n = start;
	while (n < end)
	{
		mas[i] = n;
		n++;
		i++;
	}
	mas[i] = '\0';
	return (mas);
}
