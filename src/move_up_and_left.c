#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
** norme: 6 functions in the file
** norme: 42 header not at top of the file
*/

char		**move_up(char **matrix, char **tmp, int x, int y)
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

char		**move_up_and_left(char **matrix)
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

static int	ft_challelemline(char *str, char c)
{
	while (*str)
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}

static int	ft_challelemcolumn(char **matrix, int n, char c)
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

int			ft_clear_line(char **matrix)
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

int			ft_clear_column(char **matrix)
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
