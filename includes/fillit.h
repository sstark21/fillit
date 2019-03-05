#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef	struct		s_tetra
{
	char			**tetraminka;
	int				w;
	int				h;
	struct s_tetra	*next;
}					t_tetra;

/*
** Validation
*/

int			wh_validation(int x, int y);
int			lst_validation(char **mx, char ch);
int			ft_replace_and_check_valid_figure(char **mx, char ch);

/*
** Move_up_and_left
*/

char	**move_up(char **matrix, char **tmp, int x, int y);
char	**move_up_and_left(char **matrix);
int		ft_challelemline(char *str, char c);
int		ft_challelemcolumn(char **matrix, int n, char c);
int		ft_clear_line(char **matrix);
int		ft_clear_column(char **matrix);

int		ft_read(char *line, t_tetra **lists);
int		get_next_line(const int fd, char **line);

/*
** Solve/helper
*/

int		ft_n_sharps(t_tetra *lists);
int		the_biggest_sqwr(int sh);
char	**ft_create_map(int sqr);

/*
** Solution
*/

int		check_space(char **mtx, t_tetra *tetra, int x, int y);
int		put_tetra(char **mtx, t_tetra *tetra, int x, int y);
int		dell_tetra(char **mtx, t_tetra *tetra, int x, int y);
int		solution(char **mtx, t_tetra *tetra, int x, int y, int sqr);
void	ft_clear_mrx(char **mtx);

#endif
