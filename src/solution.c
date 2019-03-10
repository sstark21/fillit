/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:57:30 by sstark            #+#    #+#             */
/*   Updated: 2019/03/10 16:50:21 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** solution have 5 parameters
*/

int	check_space(char **mtx, t_tetra *tetra, int x, int y)
{
	int xx;
	int yy;
	int start_x;

	start_x = x;
	yy = 0;
	while (tetra->h > yy)
	{
		xx = 0;
		while (tetra->w > xx)
		{
			if ((tetra->tetraminka)[yy][xx] != '.' && mtx[y][x] != '.')
				return (0);
			x++;
			xx++;
			if ((tetra->tetraminka)[yy][xx] == '\0')
			{
				y++;
				yy++;
				x = start_x;
			}
		}
	}
	return (1);
}

int	put_tetra(char **mtx, t_tetra *tetra, int x, int y)
{
	int xx;
	int yy;
	int start_x;

	start_x = x;
	yy = 0;
	while (tetra->h > yy)
	{
		xx = 0;
		while (tetra->w > xx)
		{
			if (mtx[y][x] == '.')
				mtx[y][x] = (tetra->tetraminka)[yy][xx];
			x++;
			xx++;
			if ((tetra->tetraminka)[yy][xx] == '\0')
			{
				y++;
				yy++;
				x = start_x;
			}
		}
	}
	return (1);
}

int	dell_tetra(char **mtx, t_tetra *tetra, int x, int y)
{
	int xx;
	int yy;
	int start_x;

	start_x = x;
	yy = 0;
	while (tetra->h > yy)
	{
		xx = 0;
		while (tetra->w > xx)
		{
			if (mtx[y][x] == (tetra->tetraminka)[yy][xx])
				mtx[y][x] = '.';
			x++;
			xx++;
			if ((tetra->tetraminka)[yy][xx] == '\0')
			{
				y++;
				yy++;
				x = start_x;
			}
		}
	}
	return (1);
}

int	solution(char **mtx, t_tetra *tetra, int y, int sqr)
{
	int x;

	x = 0;
	if (!tetra)
		return (1);
	while (tetra->h + y <= sqr)
	{
		while (tetra->w + x <= sqr)
		{
			if (check_space(mtx, tetra, x, y))
			{
				put_tetra(mtx, tetra, x, y);
				if (solution(mtx, tetra->next, 0, sqr))
					return (1);
				dell_tetra(mtx, tetra, x, y);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}
