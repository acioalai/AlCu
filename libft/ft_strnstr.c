/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:10:30 by alaza             #+#    #+#             */
/*   Updated: 2014/11/08 20:20:49 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	k;
	char	*cstr2;

	i = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[i] && i < n)
	{
		cstr2 = (char *)str2;
		k = 0;
		if (str2[k] == '\0')
			return ((char *)str1);
		while (str1[i + k] == cstr2[k] && cstr2[k] && i + k < n)
			k++;
		if (cstr2[k] == '\0')
			return ((char *)(str1 + i));
		i++;
	}
	return (NULL);
}
