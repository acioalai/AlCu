/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 17:39:48 by alaza             #+#    #+#             */
/*   Updated: 2015/12/05 17:08:59 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*copy_node(t_list *node)
{
	t_list		*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->content = malloc(sizeof(char) * node->content_size);
	ft_memcpy(new->content, node->content, node->content_size);
	new->content_size = node->content_size;
	new->next = NULL;
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*begin_new;
	t_list		*prev;

	begin_new = NULL;
	while (lst != NULL)
	{
		if ((new = copy_node((*f)(lst))) == NULL)
			return (NULL);
		if (begin_new == NULL)
			begin_new = new;
		else
			prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (begin_new);
}
