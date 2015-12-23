/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acioalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:18:28 by acioalai          #+#    #+#             */
/*   Updated: 2015/12/20 23:16:25 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	print_line(t_line *line)
{
	int		i;

	i = -1;
	while (++i < line->nb_matches)
		ft_putstr("\033[33m\033[1m| \033[0m");
	ft_putstr("\n");
}

int		check_user_input(char *input, int nb_matches)
{
	int		i;
	int		nbr;

	i = -1;
	while (input[++i] != '\0')
		if (!ft_isdigit(input[i]))
			return (0);
	nbr = ft_atoi(input);
	if (nbr < 1 || nbr > 3)
		return (0);
	if (nbr > nb_matches)
		return (0);
	return (nbr);
}

void	user_turn(t_line *line, t_line *begin_list)
{
	char	*user_input;
	int		i;
	int		input;

	ft_putstr("Your turn:\n");
	print_map(begin_list);
	input = 0;
	while (input == 0)
	{
		ft_putstr("\033[1mChoose a number of matches to remove: \033[0m");
		get_next_line(0, &user_input);
		i = -1;
		input = check_user_input(user_input, line->nb_matches);
	}
	line->nb_matches -= input;
	ft_putstr("--------------------------------------\n");
}

int		computer_decision(t_line *line)
{
	int		rst;

	rst = line->nb_matches % 4;
	if (rst == 1)
		return (1);
	if (line->last_player == USR)
	{
		if (rst == 0)
			return (3);
		if (rst == 2)
			return (1);
		if (rst == 3)
			return (2);
	}
	else if (line->last_player == CPU)
	{
		if (rst == 0)
			return (1);
		else if (rst == 2)
			return (2);
		else if (rst == 3)
			return (3);
	}
	return (0);
}

void	computer_turn(t_line *line, t_line *begin_list)
{
	int		remove;
	char	str[8];

	remove = computer_decision(line);
	if (!(line->nb_matches - remove == 0 && line->prev == NULL))
	{
		ft_putstr("Computer's turn:\n");
		print_map(begin_list);
		ft_putstr("--------------------------------------\n");
		if (remove == 1)
			ft_strcpy(str, "match");
		else
			ft_strcpy(str, "matches");
		ft_putstr("(computer removed ");
		ft_putnbr(remove);
		ft_putstr(" ");
		ft_putstr(str);
		ft_putstr(")\n");
		line->nb_matches -= remove;
	}
}
