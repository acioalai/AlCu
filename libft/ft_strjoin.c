/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 01:32:53 by alaza             #+#    #+#             */
/*   Updated: 2014/11/12 11:32:25 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		k;
	int		s1len;
	int		s2len;

	i = 0;
	k = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (s1len + s2len) + 1)))
		return (NULL);
	ft_memset(new, 0, s1len + s2len + 1);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		new[i + k] = s2[k];
		k++;
	}
	return (new);
}
