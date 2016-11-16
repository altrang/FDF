/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 10:00:44 by atrang            #+#    #+#             */
/*   Updated: 2016/03/31 10:17:59 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double			main()
{
	double x1 = -2.1;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;
	double image_x = 270;
	double image_y = 240;
	double i_max = 50;
	double zoom_x = image_x / (x2 - x1);
	double zoom_y = image_y / (y2 - y1);
	double x = 0;
	double y;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	double i;
	double tmp;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "fractol");
	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			c_r = x / zoom_x + x1;
			c_i = y / zoom_y + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			y++;
		}
            while (z_r * z_r + z_i * z_i < 4 && i < i_max)
            {
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
            	z_i = 2 * z_i * tmp + c_i;
            	i = i + 1;
            	if (i == i_max)
            		mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
            }
		x++;
	}
	mlx_loop(mlx);
}
