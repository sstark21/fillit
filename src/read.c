#include "../includes/fillit.h"
#include <stdio.h>
#include <stdlib.h>

/*
** norme: 6 functions in the file
** norme: 42 header not at top of the file
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

t_tetra	*create_ell(char ***elem)
{
	t_tetra		*new_tetra;

	if (!(new_tetra = (t_tetra*)malloc(sizeof(t_tetra))))
	{
		ft_putendl("error");
		return (NULL);
	}
	(*new_tetra).h = ft_clear_line(*elem);
	(*new_tetra).w = ft_clear_column(*elem);
	(*new_tetra).tetraminka = (*elem);
	(*new_tetra).next = NULL;
	return (new_tetra);
}

/*
** with gnl get map and put to array
** if 5s string not 0 - return positive volume in the last string, return 0
*/

int		getarray(int fd, char ***arr, char ch)
{
	int			f;
	int			i;

	i = 0;
	*arr = (char **)malloc(sizeof(char *) * 5);
	while (i < 4)
	{
		if (!get_next_line(fd, &((*arr)[i++])))
			emergency_exit(lists);
	}
	if (!ft_replace_and_check_valid_figure(&arr[0][0], ch))
		emergency_exit(lists);
	f = get_next_line(fd, &((*arr)[i]));
	(*arr)[i] = NULL;
	return (f);
}

/*
** get list and crate element
*/

int		getlist(int fd, t_tetra **list, char ch)
{
	int			i;
	char		**arr;

	arr = NULL;
	i = 0;
	i = getarray(fd, &arr, ch);
	if (!lst_validation(arr, ch))
		emergency_exit(lists);
	*list = create_ell(&arr);
	if (!wh_validation((*list)->w, (*list)->h))
		emergency_exit(lists);
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
	while (getlist(fd, &list, ch++))
		l_back_push(lists, list);
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
