/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:55:15 by alaza             #+#    #+#             */
/*   Updated: 2014/11/13 00:10:25 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*z;

	if (size == 0)
		return (NULL);
	if (!(z = malloc(sizeof(char) * size)))
		return (NULL);
	ft_memset(z, 0, size);
	return (z);
}
