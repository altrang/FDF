/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:10:34 by atrang            #+#    #+#             */
/*   Updated: 2016/03/28 16:44:09 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_v			*ft_draw_tab(char *str, t_v *v, int r, t_fp f_p)
{
	char	*s;
	char	**s2;
	int		t[5];

	t[1] = 0;
	t[2] = 0;
	if (!(t[4] = open(str, O_RDONLY)))
		ft_error();
	while (get_next_line(t[4], &s) == 1)
	{
		t[0] = 0;
		t[3] = -1;
		s2 = ft_strsplit(s, ' ');
		while (++t[3] < v[t[2]].i)
		{
			v[t[2]].t[t[3]].z = ft_atoi(s2[t[0]]) * 5;
			v[t[2]].t[t[3]].x = t[0] * (r) - (t[1] * r / 2) + f_p.x - 200;
			v[t[2]].t[t[3]].y = t[1] * (r) + (t[0] * (r / 2))
			- v[t[2]].t[t[3]].z + f_p.y;
			t[0]++;
		}
		t[2]++;
		t[1]++;
	}
	return (v);
}
