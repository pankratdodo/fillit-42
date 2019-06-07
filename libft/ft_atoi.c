/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:41:30 by caellis           #+#    #+#             */
/*   Updated: 2019/05/04 16:16:27 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skipws_setneg(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
	{
		(*str)++;
		return (1);
	}
	else if (**str == '+')
		(*str)++;
	return (0);
}

int			ft_atoi(const char *str)
{
	char		*s;
	long int	num;
	int			neg;

	s = (char *)str;
	num = 0;
	neg = skipws_setneg(&s);
	while (ft_isdigit(*s))
	{
		if (num * 10 / 10 != num)
		{
			if (neg)
				return (0);
			return (-1);
		}
		num = num * 10 + (*s - '0');
		s++;
	}
	if (neg)
		return (-num);
	return (num);
}
