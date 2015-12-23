/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acioalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:35:42 by acioalai          #+#    #+#             */
/*   Updated: 2015/12/21 17:13:43 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	free_list(t_line **begin_list)
{
	t_line	*temp;
	t_line	*aux;

	temp = *begin_list;
	while (temp != NULL)
	{
		aux = temp->next;
		free(temp);
		temp = aux;
	}
	*begin_list = NULL;
}

void	game_over(int loser)
{
	if (loser == USR)
		ft_putstr("\033[31m\033[1mComputer wins!\033[0m\n");
	else
		ft_putstr("\033[32m\033[1mYou win!\033[0m\n");
}

int		choose_turn(void)
{
	char	*answer;

	while (1)
	{
		ft_putstr("Do you want to have the first turn? [y/n] ");
		get_next_line(0, &answer);
		if (ft_strcmp(answer, "y") == 0)
			return (USR);
		if (ft_strcmp(answer, "n") == 0)
			return (CPU);
	}
}

void	print_map(t_line *line)
{
	while (line != NULL)
	{
		print_line(line);
		line = line->next;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_line	*begin_list;

	begin_list = NULL;
	if (argc < 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1 || read_input(fd, &begin_list) == -1)
	{
		ft_putendl_fd("ERROR", 2);
		return (-1);
	}
	print_map(begin_list);
	display(begin_list, choose_turn());
	if (fd > 0)
		close(fd);
	if (begin_list != NULL)
		free_list(&begin_list);
	return (0);
}
