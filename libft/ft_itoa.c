/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft97_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:32:45 by alaza             #+#    #+#             */
/*   Updated: 2014/11/13 02:39:00 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_ntostring(int n, char *string)
{
	int			len;
	long int	l_nbr;
	int			i;

	i = 0;
	len = ft_nbrlen(n);
	l_nbr = n;
	if (l_nbr < 0)
	{
		l_nbr *= -1;
		string[len] = '-';
	}
	while (l_nbr)
	{
		string[i] = l_nbr % 10 + 48;
		l_nbr /= 10;
		i++;
	}
}

char			*ft_itoa(int n)
{
	int		len;
	char	*new;
	char	*string;

	if (n == 0)
	{
		new = ft_strnew(2);
		new[0] = '0';
		return (new);
	}
	string = ft_strnew(15);
	ft_ntostring(n, string);
	len = ft_nbrlen(n);
	if (n < 0)
		len++;
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strcpy(new, string);
	ft_strrev(new);
	return (new);
}
