/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:14:08 by caellis           #+#    #+#             */
/*   Updated: 2019/05/04 16:35:01 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	if (lst && f)
	{
		new = (*f)(lst);
		new->next = ft_lstmap(lst->next, f);
		if (lst->next && (!new->next))
		{
			free(new->content);
			ft_memdel((void**)&new);
			return (NULL);
		}
	}
	return (new);
}
