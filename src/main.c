/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:56:50 by sstark            #+#    #+#             */
/*   Updated: 2019/03/10 16:48:16 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

char	**ft_solve(char *line)
{
	t_tetra	*lists;
	int		sh;
	int		sharp;
	char	**map;

	lists = NULL;
	ft_read(line, &lists);
	sharp = ft_n_sharps(lists);
	sh = the_biggest_sqwr(sharp);
	map = ft_create_map(sh);
	while (!solution(map, lists, 0, sh))
	{
		ft_clear_mtx(map);
		map = ft_create_map(++sh);
	}
	free(lists);
	return (map);
}

int		ft_fillit(char *line)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = ft_solve(line);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	ft_clear_mtx(map);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file");
		return (1);
	}
	else
		ft_fillit(argv[1]);
	return (0);
}
