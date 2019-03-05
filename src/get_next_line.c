/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:20:28 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/12 16:59:40 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_strlen_mod(char *ch)
{
	int				i;

	i = 0;
	while (ch[i] && ch[i] != '\n')
	{
		i++;
	}
	return (i);
}

static char		*ft_cut_n_place(char **str)
{
	int				i;
	char			*tmp1;
	char			*tmp2;

	i = ft_strlen_mod(*str);
	tmp1 = ft_strnew(i);
	ft_strncpy(tmp1, *str, i);
	if (*(*str + i))
		tmp2 = ft_strdup(*str + i + 1);
	else
		tmp2 = ft_strnew(0);
	free(*str);
	*str = tmp2;
	return (tmp1);
}

static int		snake(char **str, int fd)
{
	char			s1[BUFF_SIZE + 1];
	char			*s2;
	int				i;

	ft_bzero(s1, BUFF_SIZE + 1);
	i = read(fd, s1, BUFF_SIZE);
	if (i == -1)
		return (-1);
	s2 = ft_strjoin(*str, s1);
	free(*str);
	*str = s2;
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[1024];
	char			*a;
	int				i;

	i = 1;
	if (fd < 0 || fd > 1024 || !(line))
		return (-1);
	if (str[fd] == NULL)
	{
		str[fd] = ft_strnew(BUFF_SIZE);
		if ((read(fd, str[fd], BUFF_SIZE)) == -1)
			return (-1);
	}
	if (!(ft_strchr(str[fd], '\n')))
	{
		while (!(ft_strchr(str[fd], '\n')) && i > 0)
		{
			i = snake(&str[fd], fd);
		}
		*line = ft_cut_n_place(&str[fd]);
	}
	else
	{
		*line = ft_cut_n_place(&str[fd]);
	}
	return (i > 0 || ft_strlen(*line) ? 1 : i);
}
