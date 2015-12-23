/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 02:58:35 by alaza             #+#    #+#             */
/*   Updated: 2015/12/05 17:28:06 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *str, char c, int len[])
{
	int		word;
	int		s;

	word = 0;
	s = 0;
	while (str[s])
	{
		while (str[s] == c)
			s++;
		if (str[s] != c && str[s] != '\0')
		{
			len[word] = 0;
			while (str[s] != c && str[s] != '\0')
			{
				len[word]++;
				s++;
			}
			word++;
		}
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		len[100];
	char	**m;
	int		i;
	int		k;
	int		si;

	i = 0;
	si = 0;
	if (!s || !(m = (char **)malloc(sizeof(char *) * ft_count(s, c, len) + 1)))
		return (NULL);
	while (s[si])
	{
		while (s[si] == c)
			si++;
		if (s[si] != c && s[si] != '\0')
		{
			k = 0;
			*(m + i) = (char *)malloc(sizeof(char) * len[i] + 1);
			while (s[si] != c && s[si] != '\0')
				m[i][k++] = s[si++];
			i++;
		}
	}
	m[i] = 0;
	return (m);
}
