/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:02:53 by apissier          #+#    #+#             */
/*   Updated: 2017/01/13 16:16:24 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <string.h>

# define BUFF_SIZE 10

typedef struct		s_fd
{
	int				n_fd;
	char			*str;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif
