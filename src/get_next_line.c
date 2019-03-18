/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:13:53 by gkoch             #+#    #+#             */
/*   Updated: 2019/03/18 19:38:52 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int	ft_set_line(char **line, char **turn)
{
	char	*item;

	if ((item = ft_strchr(*turn, '\n')))
	{
		item[0] = '\0';
		*line = ft_strdup(*turn);
		item = ft_strdup(&item[1]);
		free(*turn);
		*turn = item;
		return (1);
	}
	*line = ft_strdup(*turn);
	free(*turn);
	*turn = NULL;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int				n;
	char			buf[BUFF_SIZE + 1];
	char			*item;
	static char		*turn[259];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (turn[fd] == NULL)
		turn[fd] = ft_strdup("\0");
	while (!ft_strchr(turn[fd], '\n') && (n = read(fd, buf, BUFF_SIZE)))
	{
		buf[n] = '\0';
		if (!(turn[fd]))
			item = buf;
		else
			item = ft_strjoin(turn[fd], buf);
		free(turn[fd]);
		turn[fd] = item;
		if (ft_strchr(turn[fd], '\n') || (n == 0))
			break ;
	}
	if (turn[fd][0] == '\0' && !n)
		return (0);
	return (ft_set_line(line, &turn[fd]));
}
