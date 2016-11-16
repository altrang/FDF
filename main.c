/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:17:56 by pcalime           #+#    #+#             */
/*   Updated: 2016/09/02 11:17:13 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_exit_win(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_exit(void *param)
{
	exit(0);
}

int		ft_draw(void *param)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (((t_data*)param)->tab[y].t != NULL)
	{
		i = 0;
		while (i < ((t_data*)param)->tab[y].i)
		{
			if (i < ((t_data*)param)->tab[y].i - 1)
				ft_draw_line(*((t_data*)param), ((t_data*)param)->tab[y].t[i],
					((t_data*)param)->tab[y].t[i + 1]);
			if (((t_data*)param)->tab[y + 1].t != NULL &&
				i <= ((t_data*)param)->tab[y + 1].i)
				ft_draw_line(*((t_data*)param), ((t_data*)param)->tab[y].t[i],
					((t_data*)param)->tab[y + 1].t[i]);
			i++;
		}
		y++;
	}
	return (0);
}

void	ft_draw_fdf(char *s)
{
	t_data		data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF");
	data.tab = ft_create_tab(s);
	mlx_string_put(data.mlx, data.win, 35, 35, 0xFFFFFF,
		"To close window : Esc or Mouse click");
	mlx_loop_hook(data.mlx, &ft_draw, &data);
	mlx_hook(data.win, 2, 0, &ft_exit_win, &data);
	mlx_hook(data.win, 17, 0, &ft_exit, &data);
	mlx_loop(data.mlx);
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 1)
		ft_putendl("Error : too few arguments :(");
	if (argc > 2)
		ft_putendl("Error : too many arguments :(");
	else if ((fd = open(argv[1], O_RDONLY)) <= 0)
		ft_error();
	else if (argc == 2)
	{
		ft_test_error(argv[1]);
		ft_draw_fdf(argv[1]);
	}
	return (0);
}


int		ft_addition(int a, int b)
{
	int c;

	c = a / b;

	return (c);
}
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_multiplication(int c)
{
	int d;

	d = c * 2;
	return (d);
}

int main()
{
	int alban;
	int bonon;
	int d;
	int e;

	alban = 2;
	bonon = 4;
	d = ft_addition(alban, bonon);
	e = ft_multiplication(d);
	ft_putchar(e);
	return (0);
}
