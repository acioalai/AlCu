/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:05:44 by alaza             #+#    #+#             */
/*   Updated: 2015/12/05 14:44:53 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		if (content == NULL)
		{
			(*new).content = NULL;
			(*new).content_size = 0;
		}
		else
		{
			(*new).content = ft_memalloc(content_size);
			memcpy((*new).content, content, content_size);
			(*new).content_size = content_size;
		}
		(*new).next = NULL;
	}
	return (new);
}
