/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:57:49 by sstark            #+#    #+#             */
/*   Updated: 2019/03/10 20:29:42 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

/*
** norme: function lst_validation has 32 lines
** norme: function ft_replace_and_check_valid_figure has 34 lines
*/

int	wh_validation(int x, int y)
{
	if ((x * y) != 4 && (x * y) != 6)
		return (0);
	return (1);
}

int	lst_validation(char **mx, char ch)
{
	int connect;

	connect = lst_validation_loop(mx, ch, 0, 0);
	if (connect == 6 || connect == 8)
	{
		if (ch < 'Z')
			return (1);
	}
	return (0);
}

int	lst_validation_loop(char **mx, char ch, int x, int y)
{
	int connect;

	connect = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (mx[x][y] == ch)
			{
				if ((x + 1 < 4) && mx[x + 1][y] == ch)
					connect++;
				if ((x - 1 >= 0) && mx[x - 1][y] == ch)
					connect++;
				if ((y + 1 < 4) && mx[x][y + 1] == ch)
					connect++;
				if ((y - 1 >= 0) && mx[x][y - 1] == ch)
					connect++;
			}
			y++;
		}
		x++;
	}
	return (connect);
}

int	ft_replace_and_check_valid_figure(char **mx, char ch)
{
	if (cheker2000(mx, ch, 0, 0) == 0)
	{
		ft_putendl("error");
		exit(0);
	}
	return (1);
}

int	cheker2000(char **mx, char ch, int x, int sharps)
{
	int	dots;
	int y;

	dots = 0;
	while (x < 4)
	{
		if (ft_strlen(mx[x]) != 4 || ((!mx[x + 1]) && (x + 1 < 4)))
			return (0);
		y = 0;
		while (y < 4)
		{
			if (mx[x][y] == '#')
			{
				mx[x][y] = ch;
				sharps++;
			}
			else if (mx[x][y] == '.')
				dots++;
			else
				return (0);
			y++;
		}
		x++;
	}
	return ((dots != 12 || sharps != 4) == 0 ? 1 : 0);
}
