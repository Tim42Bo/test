/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:32:24 by tbornema          #+#    #+#             */
/*   Updated: 2023/11/27 16:59:03 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	open_window(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
	{
		ft_printf("Error initializing MLX\n");
		exit(1);
	}
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	if (!fractol)
	{
		ft_printf("Error creating window\n");
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		exit(1);
	}
}

void	draw_rectangle(t_fractol *fractol, int color1, int color2)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x > 400)
				mlx_pixel_put(fractol->mlx, fractol->window, x, y, color2);
			else
				mlx_pixel_put(fractol->mlx, fractol->window, x, y, color1);
			x++;
		}
		y++;
	}
}

int	main(int argc, char *argv[])
{
	t_fractol fractol;

	fractol.zoom = 0.005;
	fractol.center.real = 0.0;
	fractol.center.unreal = 0.0;

	if ((argc == 2  && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];
		if (!ft_strncmp(fractol.name, "julia", 5))
		{
			fractol.julia_x = ft_atod(argv[2]);
			fractol.julia_y = ft_atod(argv[3]);
		}
		
		open_window(&fractol);
		mlx_mouse_hook(fractol.window, ft_mouse_hook, &fractol);
    	mlx_key_hook(fractol.window, ft_key_hook, &fractol);
		
		ft_render_fractal(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		ft_printf("./fractol mandelbrot\n or \n./fractol julia <value_1> <value_2>\n");
		exit(1);
	}
	return (0);
}