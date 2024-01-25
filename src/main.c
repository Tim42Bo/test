/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:32:24 by tbornema          #+#    #+#             */
/*   Updated: 2024/01/16 14:51:39 by tbornema         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_fractol *fractol;
	fractol = ft_calloc(sizeof(*fractol), 1);

	fractol->zoom = 0.005;
	fractol->center.real = 0.0;
	fractol->center.unreal = 0.0;

	if ((argc == 2  && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol->name = argv[1];
		if (!ft_strncmp(fractol->name, "julia", 5))
		{
			fractol->julia_x = ft_atod(argv[2]);
			fractol->julia_y = ft_atod(argv[3]);
		}
		
		open_window(fractol);
		mlx_mouse_hook(fractol->window, ft_mouse_hook, fractol);
    	mlx_key_hook(fractol->window, ft_key_hook, fractol);
		ft_render_fractal(fractol);
		mlx_loop(fractol->mlx);
	}
	else
	{
		ft_printf("./fractol mandelbrot\n or \n./fractol julia <value_1> <value_2>\n");
		exit(1);
	}
	return (0);
}

/*c = -0.4 + 0.6i
c = 0.285 + 0i
c = 0.285 + 0.01i
c = -0.8 + 0.156i
c = -0.70176 - 0.3842i
c = -0.835 - 0.2321i
c = -0.8 + 0.156i*/