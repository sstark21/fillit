/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:57:16 by sstark            #+#    #+#             */
/*   Updated: 2019/03/10 16:41:58 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdlib.h>

/*
** norme: 6 functions in the file
*/

int		l_back_push(t_tetra **start, t_tetra *data)
{
	t_tetra		*next_tetra;

	if (!data)
		return (1);
	next_tetra = *start;
	if (next_tetra)
	{
		while ((*next_tetra).next)
			next_tetra = (*next_tetra).next;
		(*next_tetra).next = data;
	}
	else
		*start = data;
	return (0);
}

/*
** with gnl get map and put to array
** if 5s string not 0 - return positive volume in the last string, return 0
*/

int		getarray(int fd, char ***arr, t_tetra **lists, char ch)
{
	int			f;
	int			i;

	i = 0;
	*arr = (char **)malloc(sizeof(char *) * 5);
	while (i < 4)
	{
		if (!get_next_line(fd, &((*arr)[i++])))
		{
			emergency_exit(lists);
		}
	}
	if (!ft_replace_and_check_valid_figure(&arr[0][0], ch))
		emergency_exit(lists);
	f = get_next_line(fd, &((*arr)[i]));
	if ((*arr)[i] && (ft_strcmp((*arr)[i], "")))
	{
		emergency_exit(lists);
	}
	(*arr)[i] = NULL;
	return (f);
}

/*
** get list and crate element
*/

int		getlist(int fd, t_tetra **lists, t_tetra **list, char ch)
{
	int			i;
	char		**arr;

	arr = NULL;
	i = 0;
	i = getarray(fd, &arr, lists, ch);
	if (!lst_validation(arr, ch))
	{
		ft_clear_mtx(arr);
		emergency_exit(lists);
	}
	*list = create_ell(&arr);
	if (!wh_validation((*list)->w, (*list)->h))
	{
		ft_clear_mtx(arr);
		ft_clear_lists(list);
		emergency_exit(lists);
	}
	return (i);
}

/*
** create file and push
*/

int		ft_create(int fd, t_tetra **lists)
{
	t_tetra		*list;
	char		ch;

	ch = 'A';
	while (getlist(fd, lists, &list, ch++))
	{
		l_back_push(lists, list);
	}
	l_back_push(lists, list);
	return (0);
}

/*
** read the file
*/

int		ft_read(char *line, t_tetra **lists)
{
	int			fd;

	fd = open(line, O_RDONLY);
	if (line && fd)
		ft_create(fd, lists);
	else
		ft_putendl("error");
	return (0);
}
