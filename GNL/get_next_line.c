/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 18:46:55 by apissier          #+#    #+#             */
/*   Updated: 2017/01/05 12:03:24 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int				check_end_of_line(char **save, char **line)
{
	char				*tmp;
	int					i;

	i = 0;
	tmp = NULL;
	if (*save)
		if (ft_strchr(*save, '\n') != NULL)
		{
			tmp = ft_strchr(*save, '\n');
			*tmp = '\0';
			while (save[i])
			{
				if (*save[i] == '\n')
					*save[i] = '\0';
				i++;
			}
			if (!(*line = ft_strdup(*save)))
				return (0);
			if (!(*save = ft_strdup(&tmp[1])))
				return (0);
			return (1);
		}
	return (0);
}

static int				while_read(const int fd, char *buf, char **save, \
						char **line)
{
	int					ret;
	char				*ptr;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ptr = ft_strjoin(*save, buf);
		if (!ptr)
			return (-1);
		free(*save);
		*save = ptr;
		if (check_end_of_line(save, line))
		{
			free(ptr);
			return (1);
		}
	}
	if (ret < 0)
		return (-1);
	return (0);
}

int						get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	static char			*save;

	if (check_end_of_line(&save, line))
		return (1);
	if (!save)
		save = ft_strnew(1);
	if (while_read(fd, buf, &save, line) > 0)
		return (1);
	else if (while_read(fd, buf, &save, line) < 0)
		return (-1);
	if (save)
	{
		*line = ft_strdup(save);
		if (ft_strlen(save) == 0)
			return (0);
		save = NULL;
		return (1);
	}
	return (0);
}
