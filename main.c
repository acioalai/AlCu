/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acioalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:35:42 by acioalai          #+#    #+#             */
/*   Updated: 2015/12/20 15:37:23 by acioalai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_line	*begin_list;

	begin_list = NULL;
	if (argc < 2)
		read_input(0, &begin_list);
	else
	{
		if (((fd = open(argv[1], O_RDONLY)) < 0) ||
				(read_input(fd, &begin_list) == -1))
		{
			ft_putendl_fd("ERROR", 2);
			return (-1);
		}
		else
			display(begin_list, USR);
	}
	return (0);
}
