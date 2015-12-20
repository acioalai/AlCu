/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 11:20:39 by alaza             #+#    #+#             */
/*   Updated: 2014/11/23 21:22:39 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 42

void	ft_memory(char ***save);
int		ft_find_newline(char *string);
int		ft_read(int const fd, char **buff);
int		ft_check(char **string, char **line, char **save);
int		get_next_line(int const fd, char **line);

#endif
