/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:44:57 by alaza             #+#    #+#             */
/*   Updated: 2014/11/11 17:45:02 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
		return ;
	}
	ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}