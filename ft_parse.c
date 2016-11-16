/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:54:19 by atrang            #+#    #+#             */
/*   Updated: 2016/05/16 18:24:34 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_pts(char *str)
{
	int			i;
	char		**s;

	i = 0;
	s = ft_strsplit(str, ' ');
	while (s[i])
		i++;
	return (i);
}

void		ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void		ft_test_error(char *str)
{
	int			fd;
	char		*s;
	int			y;
	int			i;
	int			e;

	y = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error();
	while (get_next_line(fd, &s) == 1)
	{
		y++;
		i = ft_pts(s);
		if (y > 1 && i != e)
			ft_error();
		e = i;
	}
	if (y < 1)
		ft_error();
	close(fd);
}

t_v			*ft_create_tab(char *str)
{
	int			fd;
	char		*s;
	int			y;
	t_v			*tab;

	y = 0;
	if ((fd = open(str, O_RDONLY)) <= 0)
		ft_error();
	while (get_next_line(fd, &s) == 1)
		y++;
	tab = malloc(sizeof(t_v) * (y + 1));
	tab[y].t = NULL;
	close(fd);
	if (!(fd = open(str, O_RDONLY)))
		ft_error();
	y = 0;
	while (get_next_line(fd, &s) == 1)
	{
		tab[y].t = (t_point*)malloc(sizeof(t_point) * ft_pts(s));
		tab[y].i = ft_pts(s);
		y++;
	}
	ft_ratio(tab, str);
	return (tab);
}

t_v			*ft_parse(char *str, t_v *v)
{
	char		*s;
	char		**s2;
	int			tab[5];

	tab[1] = 0;
	tab[2] = 0;
	tab[4] = open(str, O_RDONLY);
	while (get_next_line(tab[4], &s) == 1)
	{
		tab[0] = 0;
		tab[3] = -1;
		s2 = ft_strsplit(s, ' ');
		while (++tab[3] < v[tab[2]].i)
		{
			v[tab[2]].t[tab[3]].z = ft_atoi(s2[tab[0]]);
			v[tab[2]].t[tab[3]].x = tab[0];
			v[tab[2]].t[tab[3]].y = tab[1];
			tab[0]++;
			if (v[tab[2]].t[tab[3]].z >= 100 || v[tab[2]].t[tab[3]].z <= -100)
				ft_error();
		}
		tab[2]++;
		tab[1]++;
	}
	return (v);
}
