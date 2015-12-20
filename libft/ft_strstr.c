/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:55:13 by alaza             #+#    #+#             */
/*   Updated: 2014/11/08 19:20:35 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	int		k;
	char	*cstr2;

	i = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[i])
	{
		cstr2 = (char *)str2;
		k = 0;
		if (str2[k] == '\0')
			return ((char *)str1);
		while (str1[i + k] == cstr2[k] && cstr2[k])
			k++;
		if (cstr2[k] == '\0')
			return ((char *)(str1 + i));
		i++;
	}
	return (NULL);
}
