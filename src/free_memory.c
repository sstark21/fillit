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

int			ft_clear_lists(t_tetra **lst)
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
	return 0;
}

void emergency_exit(t_tetra **lists)
{
	// DEB;
	ft_clear_lists(lists);
	ft_putendl("error");
	exit(0);
}
