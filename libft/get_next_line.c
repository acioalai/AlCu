/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaza <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 11:20:28 by alaza             #+#    #+#             */
/*   Updated: 2014/11/23 22:38:39 by alaza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_memory(char ***save)
{
	int		i;

	i = 0;
	*save = (char **)malloc(sizeof(char *) * 100);
	while (i < 50)
	{
		(*save)[i] = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		ft_memset((*save)[i], 0, BUFF_SIZE + 1);
		i++;
	}
}

int		ft_find_newline(char *string)
{
	int		i;

	i = 0;
	while (string[i] != '\0')
	{
		while (string[i] != '\n' && string[i] != '\0')
			i++;
		if (string[i] == '\n')
			return (1);
	}
	return (0);
}

int		ft_read(int const fd, char **buff)
{
	int		rval;

	*buff = ft_strnew(BUFF_SIZE + 1);
	rval = read(fd, *buff, BUFF_SIZE);
	if (rval < BUFF_SIZE)
	{
		if ((*buff)[ft_strlen(*buff) - 1] != '\n')
			*buff = ft_strjoin(*buff, "\n");
	}
	return (rval);
}

int		ft_check(char **string, char **line, char **save)
{
	int		len;

	len = 0;
	if (ft_find_newline(*string) == 0)
		return (0);
	else if (ft_find_newline(*string) == 1)
	{
		len = (int)(ft_strchr(*string, 10) - *string + 1);
		*line = ft_strnew(len + 1);
		ft_strncpy(*line, *string, len - 1);
		*save = ft_strdup(*string + len);
		ft_strclr(*string);
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char		**save;
	char			*string;
	char			*buff;
	int				rval;

	if (save == NULL)
		ft_memory(&save);
	if (save[fd][0] != '\0')
		string = ft_strdup(save[fd]);
	else
		string = ft_strnew(BUFF_SIZE + 1);
	while (ft_check(&string, line, &(save[fd])) == 0)
	{
		rval = ft_read(fd, &buff);
		if (rval == -1)
			return (-1);
		if (rval == 0 && string[0] == 0)
			return (0);
		string = ft_strjoin(string, buff);
	}
	return (1);
}
