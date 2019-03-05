#include "./includes/fillit.h"
#include "./includes/libft.h"
#include <stdio.h>

/*
** norme: 42 header not at top of the file
*/

char	**ft_solve(char *line)
{
	t_tetra	*lists;
	int		sh;
	char	**map;

	lists = NULL;
	ft_read(line, &lists);
	sh = ft_n_sharps(lists);
	sh = the_biggest_sqwr(sh);
	map = ft_create_map(sh);
	while (!solution(map, lists, 0, 0, sh))
	{
		printf("%s\n", "\n\n\nNes wave\n\n\n");
		ft_clear_mrx(map);
		map = ft_create_map(++sh);
	}
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
