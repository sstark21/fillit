/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_and_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:56:59 by sstark            #+#    #+#             */
/*   Updated: 2019/03/10 16:36:22 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

/*
** norme: 6 functions in the file
*/

char	**move_up(char **matrix, char **tmp, int x, int y)
{
	while (matrix[0][0] == '.' && matrix[0][1] == '.' &&
	matrix[0][2] == '.' && matrix[0][3] == '.')
	{
		x = 0;
		while (x < 4)
		{
			y = 0;
			while (y < 3)
			{
				matrix[y][x] = tmp[y + 1][x];
				y++;
			}
			matrix[y][x] = '.';
			x++;
		}
	}
	return (matrix);
}

char	**move_up_and_left(char **matrix)
{
	int		x;
	int		y;
	char	**tmp;

	tmp = matrix;
	while (matrix[0][0] == '.' && matrix[1][0] == '.' && matrix[2][0] == '.' &&
	matrix[3][0] == '.')
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 3)
			{
				matrix[y][x] = tmp[y][x + 1];
				x++;
			}
			matrix[y][x] = '.';
			y++;
		}
	}
	matrix = move_up(matrix, tmp, x, y);
	return (matrix);
}

int		ft_challelemline(char *str, char c)
{
	while (*str)
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}

int		ft_challelemcolumn(char **matrix, int n, char c)
{
	int		y;

	y = 0;
	while (matrix[y])
	{
		if (matrix[y][n] != c)
			return (0);
		y++;
	}
	return (1);
}
