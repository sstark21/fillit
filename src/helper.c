#include "../includes/fillit.h"
#include "../includes/libft.h"
#include <stdio.h>

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

void	ft_clear_mrx(char **mtx)
{
	int		n;

	n = 0;
	while (mtx)
	{
		ft_strdel(&mtx[n]);
		n++;
	}
	ft_strdel(mtx);
}
