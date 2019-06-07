/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:07:11 by plettie           #+#    #+#             */
/*   Updated: 2019/05/27 17:07:12 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define onError(head){\
        free(head);\
        head = NULL;\
        return(0);\
}\

char		*ft_strchr(char *s, char resh)
{
	int		i;
    int count;

    count = 0;
	i = 0;
	while (s[i] != resh)
	{
		if (!s[i] || (s[i] != '.' && s[i] != '\n') || count > 3)
			return (0);
        if (s[i] == '\n')
            count++;
		i++;
	}
	return (&s[i]);
}

char isValid(int fd)
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
        if (kol < 20 || c[4] != '\n' || (c[9] | c[14] | c[19]) != c[4])
            return (0);
        count = kol;
        while (*c && count < 26)
        {
            c = ft_strchr(c, '#');
            if (!c)
                break;
            count++;
            if (*(c - 1) != '#' && *(c + 1) != '#' && *(c - 5) != '#' && *(c + 5) != '#')
                onError(head)
            c++;
        }
        if (count != 25 - (kol == 20) ? (1) : (0))
            onError(head)
        c = head;
    }
    if (kol == -1 || time > 26 || count != 24)
        return (0);
    return (1);
        
}

int main(int ac, char **av)
{
    int fd;
    char c;

    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    if (isValid(fd))
        write(1, "harosh", 6);
    else
        write(1, "sore ne valid", 13);
    return (0);
}