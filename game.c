/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acioalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:18:28 by acioalai          #+#    #+#             */
/*   Updated: 2015/12/20 15:34:44 by acioalai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	print_line(t_line *line)
{
	int		i;

	i = -1;
	while (++i < line->nb_matches)
		ft_putstr("| ");
	ft_putstr("\n");
}

int		check_user_input(char *input, int nb_nb_matches)
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
	if (nbr > nb_nb_matches)
		return (0);
	return (nbr);
}

void	user_turn(t_line *line)
{
	char	*user_input;
	int		i;
	int		input;

	ft_putstr("User's turn\n");
	input = 0;
	while (input == 0)
	{
		ft_putstr("Choose a number of nb_matches to remove: ");
		get_next_line(0, &user_input);
		i = -1;
		input = check_user_input(user_input, line->nb_matches);
	}
	line->nb_matches -= input;
}

void	game_over(int loser)
{
	if (loser == USR)
		ft_putstr("Computer wins!\n");
	else
		ft_putstr("User wins!\n");
}

void	computer_turn(t_line *line)
{
	int		rst;

	ft_putstr("Computer's turn\n");
	rst = line->nb_matches % 4;
	if (rst == 1)
		line->nb_matches -= 1;
	if (line->last_player == USR)
	{
		if (rst == 0)
			line->nb_matches -= 3;
		if (rst == 2)
			line->nb_matches -= 1;
		if (rst == 3)
			line->nb_matches -= 2;
	}
	else if (line->last_player == CPU)
	{
		if (rst == 0)
			line->nb_matches -= 1;
		else if (rst == 2)
			line->nb_matches -= 2;
		else if (rst == 3)
			line->nb_matches -= 3;
	}
}
