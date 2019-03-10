/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:58:18 by sstark            #+#    #+#             */
/*   Updated: 2019/03/10 20:30:29 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int					wh_validation(int x, int y);
int					lst_validation(char **mx, char ch);
int					ft_replace_and_check_valid_figure(char **mx, char ch);
int					lst_validation_loop(char **mx, char ch, int x, int y);

/*
** Move_up_and_left
*/

char				**move_up(char **matrix, char **tmp, int x, int y);
char				**move_up_and_left(char **matrix);
int					ft_challelemline(char *str, char c);
int					ft_challelemcolumn(char **matrix, int n, char c);

int					ft_read(char *line, t_tetra **lists);
int					get_next_line(const int fd, char **line);
int					cheker2000(char **mx, char ch, int x, int sharps);

/*
** helper
*/

int					ft_n_sharps(t_tetra *lists);
int					the_biggest_sqwr(int sh);
char				**ft_create_map(int sqr);
t_tetra				*create_ell(char ***elem);

/*
** Solution
*/

int					check_space(char **mtx, t_tetra *tetra, int x, int y);
int					put_tetra(char **mtx, t_tetra *tetra, int x, int y);
int					dell_tetra(char **mtx, t_tetra *tetra, int x, int y);
int					solution(char **mtx, t_tetra *tetra, int y, int sqr);

/*
** free and clear
*/

void				ft_clear_mtx(char **mtx);
int					ft_clear_lists(t_tetra **lst);
void				emergency_exit(t_tetra **lists);
int					ft_clear_line(char **matrix);
int					ft_clear_column(char **matrix);

#endif
