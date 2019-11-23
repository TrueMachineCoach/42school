/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:02:52 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/17 15:27:39 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_contentdel(void *cont, size_t len)
{
	if (!cont)
		free(cont);
	len = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *current;
	t_list *new;
	t_list *result;

	result = 0;
	if (lst && f)
	{
		result = f(lst);
		new = result;
		new->next = 0;
		current = lst->next;
		while (current && result)
		{
			new->next = f(current);
			if (!new->next)
			{
				ft_lstdel(&result, ft_contentdel);
				return (0);
			}
			current = current->next;
			new = new->next;
			new->next = 0;
		}
	}
	return (result);
}
