/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 11:25:58 by alaza             #+#    #+#             */
/*   Updated: 2014/11/10 22:14:53 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*s;
	char	*d;
	char	*save;

	s = (char *)src;
	d = (char *)dest;
	save = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	ft_strcpy(save, s);
	while (len-- > 0)
		*d++ = *save++;
	return ((void *)dest);
}
