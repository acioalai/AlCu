/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 22:50:08 by alaza             #+#    #+#             */
/*   Updated: 2014/11/16 22:50:10 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*copy;

	while (alst)
	{
		copy = *alst;
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(copy);
		if (*alst == NULL)
			alst = NULL;
	}
}
