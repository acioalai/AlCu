/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acioalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:34:59 by acioalai          #+#    #+#             */
/*   Updated: 2015/12/20 23:16:23 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		ft_winner(int nbr)
{
	int		rst;

	rst = nbr % 4;
	if (rst == 1)
		return (CPU);
	else
		return (USR);
}

void	add_node(t_line **begin_list, int nb_matches)
{
	t_line		*new;
	t_line		*temp;

	new = (t_line *)malloc(sizeof(t_line));
	temp = *begin_list;
	new->nb_matches = nb_matches;
	if (*begin_list == NULL)
	{
		new->last_player = USR;
		new->prev = NULL;
		*begin_list = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->last_player = ft_winner(temp->nb_matches);
		new->prev = temp;
	}
	new->next = NULL;
}

int		validate_line(char *line)
{
	int		i;
	int		nb;

	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (-1);
	nb = ft_atoi(line);
	if (nb >= 1 && nb <= 10000)
		return (nb);
	else
	{
		return (-1);
	}
}

int		read_input(int fd, t_line **begin_list)
{
	char	*line;
	int		nb_matches;

	while (get_next_line(fd, &line))
	{
		if (ft_strcmp(line, "") == 0)
			break ;
		if ((nb_matches = validate_line(line)) == -1)
			return (-1);
		add_node(begin_list, nb_matches);
	}
	return (0);
}

void	display(t_line *line, int turn)
{
	t_line	*temp;

	while (1)
	{
		temp = line;
		while (temp->next != NULL)
			temp = temp->next;
		if (turn == USR)
			user_turn(temp, line);
		if (turn == CPU)
			computer_turn(temp, line);
		if ((temp->nb_matches == 0) && (temp->prev == NULL))
		{
			game_over(turn);
			return ;
		}
		else if (temp->nb_matches == 0)
			temp->prev->next = NULL;
		turn = (turn + 1) % 2;
	}
}
