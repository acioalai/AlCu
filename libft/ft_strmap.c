/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:33:57 by alaza             #+#    #+#             */
/*   Updated: 2014/11/11 00:09:48 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	ft_memset(new, 0, ft_strlen(s) + 1);
	while (*p != '\0')
	{
		new[i] = f(*p);
		i++, p++;
	}
	return (new);
}
