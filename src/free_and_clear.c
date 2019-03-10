/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:56:08 by sstark            #+#    #+#             */
/*   Updated: 2019/03/10 16:29:29 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

void	ft_clear_mtx(char **mtx)
{
	int		n;

	n = 0;
	while (mtx[n])
	{
		free(mtx[n]);
		n++;
	}
	free(mtx);
	mtx = NULL;
}

int		ft_clear_lists(t_tetra **lst)
{
	t_tetra	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_clear_mtx((*lst)->tetraminka);
		(*lst)->next = NULL;
		free(*lst);
		(*lst) = NULL;
		(*lst) = tmp;
	}
	lst = NULL;
	return (0);
}

void	emergency_exit(t_tetra **lists)
{
	ft_clear_lists(lists);
	ft_putendl("error");
	exit(0);
}

int		ft_clear_line(char **matrix)
{
	int		y;
	int		x;

	y = 0;
	while (matrix[y])
	{
		if (ft_challelemline(matrix[y], '.'))
		{
			free(matrix[y]);
			x = y + 1;
			while (matrix[x])
			{
				matrix[x - 1] = matrix[x];
				x++;
			}
			matrix[x - 1] = matrix[x];
			continue ;
		}
		y++;
	}
	return (y);
}

int		ft_clear_column(char **matrix)
{
	int		n;
	int		y;
	int		x;

	n = 0;
	while (matrix[0][n])
	{
		if (ft_challelemcolumn(matrix, n, '.'))
		{
			y = -1;
			while (matrix[++y])
			{
				x = n + 1;
				while (matrix[y][x])
				{
					matrix[y][x - 1] = matrix[y][x];
					x++;
				}
				matrix[y][x - 1] = matrix[y][x];
			}
			continue;
		}
		n++;
	}
	return (n);
}
