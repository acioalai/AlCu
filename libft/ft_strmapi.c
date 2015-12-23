/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 00:10:49 by alaza             #+#    #+#             */
/*   Updated: 2015/12/05 17:23:53 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*p;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	p = (char *)s;
	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	ft_memset(new, 0, ft_strlen(s) + 1);
	while (*p != '\0')
	{
		new[i] = f(i, *p);
		i++;
		p++;
	}
	return (new);
}
