/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:42:44 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 16:18:08 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *d;

	if (alst && del)
	{
		current = *alst;
		d = 0;
		while (current)
		{
			d = current;
			current = current->next;
			del(d->content, d->content_size);
			free(d);
		}
	}
	*alst = 0;
}
