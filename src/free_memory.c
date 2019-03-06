#include "../includes/fillit.h"
#include "../includes/libft.h"

void	cleaner(char **mtx, t_tetra *lst)
{
	ft_clear_lists(lst);
	ft_clear_mrx(mtx);
}

void	ft_clear_lists(t_tetra *lst)
{
	char	*tmp;

	while (lst)
	{
		ft_clear_mtx(lst->tetraminka);
		free(lst->tetraminka);
    	free(lst->w);
		free(lst->h);
		tmp = lst->next;
		lst = lst->next;
		free(tmp);
	}
	return ;
}

void	ft_clear_mtx(char **mtx)
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