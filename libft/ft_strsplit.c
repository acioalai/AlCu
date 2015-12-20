/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 02:58:35 by alaza             #+#    #+#             */
/*   Updated: 2014/11/13 11:29:26 by alaza            ###   ########.fr       */
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
				len[word]++, s++;
			}
			word++;
		}
	}
	return (word);
}

char		**ft_strsplit(char const *str, char c)
{
	int		len[100];
	char	**matrix;
	int		i;
	int		k;
	int		s;

	i = 0;
	s = 0;
	if (!(matrix = (char **)malloc(sizeof(char *) * ft_count(str, c, len) + 1)))
		return (NULL);
	while (str[s])
	{
		while (str[s] == c)
			s++;
		if (str[s] != c && str[s] != '\0')
		{
			k = 0;
			*(matrix + i) = (char *)malloc(sizeof(char) * len[i] + 1);
			while (str[s] != c && str[s] != '\0')
				matrix[i][k++] = str[s++];
			i++;
		}
	}
	matrix[i] = 0;
	return (matrix);
}
