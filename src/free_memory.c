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

int		ft_clear_lists(t_tetra *lst)
{
	if (lst == NULL)
		return (1);
	ft_clear_mtx(lst->tetraminka);
	free(lst->tetraminka);
	lst->tetraminka = NULL;
	(void*)lst->w;
    free(lst->w);

	free(lst->h);

	ft_clear_lists(lst->next);
	free(lst->next);
	lst->next = NULL;
	free(lst);
	lst = NULL;
	return (0);
}
