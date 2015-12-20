/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 01:46:09 by alaza             #+#    #+#             */
/*   Updated: 2014/11/13 00:50:44 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		l;
	int		k;
	int		y;

	i = 0;
	k = 0;
	y = 0;
	l = ft_strlen(s);
	while (s[k] == 32 || s[k] == '\n' || s[k] == '\t')
		k++;
	if (s[k] == '\0')
	{
		new = ft_strnew(1);
		return (new);
	}
	while (s[l - 1 - i] == 32 || s[l - 1 - i] == '\n' || s[l - 1 - i] == '\t')
		i++;
	if (!(new = (char *)malloc(sizeof(char) * (l - i - k) + 1)))
		return (NULL);
	ft_memset(new, 0, l - i - k + 1);
	while (k < l - i && l - i >= 0)
		new[y++] = s[k++];
	return (new);
}
