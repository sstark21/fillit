#include "../includes/fillit.h"
#include "../includes/libft.h"
#include <stdio.h>
// void	cleaner(char **mtx, t_tetra *lst)
// {
// 	ft_clear_lists(lst);
// 	ft_clear_mrx(mtx);
// }

// void	ft_clear_lists(t_tetra *lst)
// {
// 	char	*tmp;
//
// 	while (lst)
// 	{
// 		ft_clear_mtx(lst->tetraminka);
// 		free(lst->tetraminka);
//     	free(lst->w);
// 		free(lst->h);
// 		tmp = lst->next;
// 		lst = lst->next;
// 		free(tmp);
// 	}
// 	return ;
// }

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

// int		ft_clear_lists(t_tetra **lst)
// {
// 	if (!*lst)
// 		return (0);
// 	DEB;
// 	if ((*lst)->next)
// 		{
// 			ft_clear_lists(&(*lst)->next);
// 		}
// 	ft_clear_mtx((*lst)->tetraminka);
// 	free((*lst)->tetraminka);
// 	(*lst)->tetraminka = NULL;
// 	(void)(*lst)->w;
// 	(void)(*lst)->h;
// 	free((*lst)->next);
// 	(*lst)->next = NULL;
// 	free((*lst));
// 	(*lst) = NULL;
// 	DEB;
// 	return (0);
// }

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
