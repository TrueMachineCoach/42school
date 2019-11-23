/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:56:56 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 16:24:48 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *result;

	result = (t_list*)malloc(sizeof(t_list));
	if (result)
	{
		if (content)
		{
			result->content = malloc(content_size);
			if (result->content)
				ft_memcpy(result->content, (void*)content, content_size);
			result->content_size = content_size;
		}
		else
		{
			result->content = 0;
			result->content_size = 0;
		}
		result->next = 0;
	}
	return (result);
}
