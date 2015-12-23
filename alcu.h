/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acioalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:33:22 by acioalai          #+#    #+#             */
/*   Updated: 2015/12/20 20:16:26 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include "libft.h"
# include "get_next_line.h"

# define CPU	0
# define USR	1

typedef struct		s_line
{
	int				nb_matches;
	int				last_player;
	struct s_line	*prev;
	struct s_line	*next;
}					t_line;

void				print_line(t_line *line);
void				print_map(t_line *begin_list);
void				user_turn(t_line *line, t_line *begin_list);
void				game_over(int loser);
void				computer_turn(t_line *line, t_line *begin_list);
void				display(t_line *line, int turn);
int					read_input(int fd, t_line **begin_list);

#endif
