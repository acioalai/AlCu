/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:51:44 by alaza             #+#    #+#             */
/*   Updated: 2014/11/09 22:20:59 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		a;
	int		i;

	a = -1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			a = i;
		i++;
	}
	if (c == 0)
		return ((char *)(str + i));
	if (a >= 0)
		return ((char *)(str + a));
	else
		return (NULL);
}
