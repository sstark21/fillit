#include "../includes/fillit.h"
#include "../includes/libft.h"
#include <stdio.h>

/*
** norme: 42 header not at top of the file
*/

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
	while (!solution(map, lists, 0, 0, sh))
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
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free(line);
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
