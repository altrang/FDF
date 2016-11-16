/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ratio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 13:05:24 by alban             #+#    #+#             */
/*   Updated: 2016/03/28 16:44:09 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_check_x(t_v *tab)
{
	int x;
	int y;
	int i;
	t_v	*tab1;

	y = 0;
	tab1 = tab;
	x = 0;
	while (tab[y].t != NULL)
	{
		i = 0;
		while (i < tab[y].i)
		{
			i++;
			if (x <= i)
				x = i;
		}
		y++;
	}
	return (x);
}

int			ft_check_y(t_v *tab)
{
	t_v	*tab1;
	int y;

	y = 0;
	tab1 = tab;
	while (tab[y].t != NULL)
		y++;
	return (y);
}

int			ft_calculate_ratio(t_v *tab)
{
	int		min;
	int		max;
	int		y;
	int		cmpt2;

	y = 0;
	max = 0;
	min = 0;
	while (tab[y].t != NULL)
	{
		cmpt2 = 0;
		while (cmpt2 < tab[y].i)
		{
			if (min > tab[y].t[cmpt2].z)
				min = tab[y].t[cmpt2].z;
			if (max < tab[y].t[cmpt2].z)
				max = tab[y].t[cmpt2].z;
			cmpt2 += 1;
		}
		y++;
	}
	cmpt2 = cmpt2 + y + max / 2 - min / 2 - 1;
	cmpt2 = HEIGHT / cmpt2;
	return (cmpt2);
}

t_fp		ft_first_pt(int x, int y, int ratio)
{
	t_fp			tab;

	tab.x = (WIDTH - (ratio * (x + y))) + WIDTH / 8;
	tab.y = ((HEIGHT - ratio * (x + y)) + ratio * x - (HEIGHT / 3));
	return (tab);
}

t_v			*ft_ratio(t_v *tab, char *str)
{
	int		y;
	int		x;
	int		ratio;
	t_fp	f_p;
	t_v		*tab1;

	x = ft_check_x(tab);
	y = ft_check_y(tab);
	tab1 = ft_parse(str, tab);
	ratio = ft_calculate_ratio(tab);
	f_p = ft_first_pt(x, y, ratio);
	tab1 = ft_draw_tab(str, tab, ratio, f_p);
	return (tab1);
}
