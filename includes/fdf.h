/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:10:20 by pcalime           #+#    #+#             */
/*   Updated: 2016/04/21 09:51:57 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1400
# define HEIGHT 1000
# include <mlx.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef	struct	s_vertex
{
	t_point		*t;
	int			i;
	int			y;
}				t_v;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_v			*tab;
	double		zoom;
}				t_data;

typedef struct	s_first
{
	int			x;
	int			y;
}				t_fp;

t_v				*ft_parse(char *str, t_v *v);
t_v				*ft_create_tab(char *str);
t_fp			ft_first_pt(int x, int y, int ratio);
void			ft_draw_line(t_data data, t_point p1, t_point p2);
int				ft_calculate_ratio(t_v *tab);
int				ft_check_x(t_v *tab);
int				ft_check_y(t_v *tab);
t_v				*ft_ratio(t_v *tab, char *str);
t_v				*ft_draw_tab(char *str, t_v *tab, int ratio, t_fp f_p);
void			ft_error(void);
void			ft_test_error(char *str);

#endif
