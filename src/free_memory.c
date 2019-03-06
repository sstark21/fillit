#include "../includes/fillit.h"
#include "../includes/libft.h"

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
	while (mtx)
	{
		ft_strdel(&mtx[n]);
		n++;
	}
	ft_strdel(mtx);
}

int		ft_clear_lists(t_tetra **lst)
{
	t_tetra *tmp;
	tmp = *lst;
	if (tmp == NULL)
		return (1);
	ft_clear_mtx(tmp->tetraminka);
	free(tmp->tetraminka);
	tmp->tetraminka = NULL;
	(void)tmp->w;
	(void)tmp->h;
	ft_clear_lists(((t_tetra**)(tmp->next)));
	free(tmp->next);
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
	return (0);
}

void emergency_exit(t_tetra **lists)
{
	ft_clear_lists(lists);
	ft_putendl("ERRROR !11!11ERROO!");
	exit(0);
}
