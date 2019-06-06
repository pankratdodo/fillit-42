/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:07:11 by plettie           #+#    #+#             */
/*   Updated: 2019/06/06 13:11:32 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/is_valid.h"

static char		*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	k;

	k = (char)c;
	i = 0;
	while (s[i] != k)
	{
		if (!s[i])
			return (0);
		i++;
	}
	str = (char*)s;
	return (&str[i]);
}

char        is_valid(int fd)
{
    char *c = malloc(21);
    char *head;
    int kol;
    int time;
    int count;

    head = c;
    time = 0;
    while ((kol = read(fd, c, 21)) > 0 && ++time < 27)
    {
        if (kol != 21 || c[4] != '\n' || !((c[9] | c[14] | c[19] | c[20]) == c[4]))
            return (0);
        count = 0;
        while (*c && count < 5)
        {
            c = ft_strchr(c, '#');
            if (!c)
                break;
            count++;
            if (*(c - 1) != '#' && *(c + 1) != '#' && *(c - 5) != '#' && *(c + 5) != '#')
                return (0);
            c++;
        }
        if (count != 4)
            return (0);
        c = head;
    }
    if (kol == -1 || time > 26)
        return (0);
    return (1);
        
}
