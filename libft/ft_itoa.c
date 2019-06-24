/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:53:39 by caellis           #+#    #+#             */
/*   Updated: 2019/05/06 17:17:11 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countdigits(int n)
{
	size_t	i;

	i = (n < 0) ? 2 : 1;
	while ((n = n / 10))
		i++;
	return (i);
}

static void		ft_swap(char *a, char *b)
{
	char	buff;

	buff = *a;
	*a = *b;
	*b = buff;
}

static void		ft_strrev(char *str)
{
	size_t	len;
	size_t	i;

	if (str && *str)
	{
		i = 0;
		len = ft_strlen(str) - 1;
		while (i <= len)
			ft_swap(&str[i++], &str[len--]);
	}
}

char			*ft_itoa(int n)
{
	char	*num;
	int		sign;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = (n >= 0) ? 1 : -1;
	if ((num = ft_strnew(countdigits(n))))
	{
		n = (sign >= 0) ? n : -n;
		i = 0;
		while (n > 0)
		{
			num[i++] = n % 10 + '0';
			n /= 10;
		}
		if (sign < 0)
			num[i++] = '-';
		ft_strrev(num);
	}
	return (num);
}
