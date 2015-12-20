/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:14:59 by alaza             #+#    #+#             */
/*   Updated: 2014/11/08 20:20:26 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dest[k] != '\0')
		k++;
	while (i < n && src[i] != '\0')
	{
		dest[k] = src[i];
		i++, k++;
	}
	dest[k] = '\0';
	return (dest);
}
