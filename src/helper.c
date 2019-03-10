/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:56:35 by sstark            #+#    #+#             */
/*   Updated: 2019/03/10 16:42:03 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

/*
** norme: 42 header not at top of the file
*/

int		ft_n_sharps(t_tetra *lists)
{
	int		i;
	t_tetra *arr;

	if (!lists)
		ft_putendl("No lists");
	arr = lists;
	i = 4;
	while (arr->next)
	{
		arr = arr->next;
		i = i + 4;
	}
	return (i);
}

int		the_biggest_sqwr(int sh)
{
	int		i;

	i = 2;
	if (sh < 4)
		ft_putendl("sh < 4");
	while (i * i < sh)
		i++;
	return (i);
}

char	**ft_create_map(int sqr)
{
	char	**mx;
	int		x;
	int		y;

	mx = (char**)malloc(sizeof(char*) * (sqr + 1));
	x = 0;
	while (x < sqr)
	{
		mx[x] = (char*)malloc(sizeof(char*) * (sqr + 1));
		y = 0;
		while (y < sqr)
		{
			mx[x][y] = '.';
			y++;
		}
		mx[x][y] = '\0';
		x++;
	}
	mx[x] = NULL;
	return (mx);
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
