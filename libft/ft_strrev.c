/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 13:04:24 by alaza             #+#    #+#             */
/*   Updated: 2014/11/13 02:42:14 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		indexbeg;
	int		indexfin;
	char	aux;

	indexbeg = 0;
	indexfin = 0;
	while (*(str + indexfin) != '\0')
		indexfin++;
	indexfin--;
	while (indexbeg <= indexfin)
	{
		aux = *(str + indexbeg);
		*(str + indexbeg) = *(str + indexfin);
		*(str + indexfin) = aux;
		indexbeg++;
		indexfin--;
	}
	return (str);
}
