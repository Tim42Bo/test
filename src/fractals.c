/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:19:51 by tbornema          #+#    #+#             */
/*   Updated: 2023/11/27 17:08:36 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;
	double		temp;
	
	z.real = 0;
	z.unreal = 0;
	iter = 0;
	while (z.real * z.real + z.unreal * z.unreal <= 4 && iter < max_iter)
	{
		temp = z.real * z.real - z.unreal * z.unreal + c.real;
		z.unreal = 2 * z.real * z.unreal + c.unreal;
		z.real = temp;
		iter++;
	}
	return (iter);
}

int ft_julia(t_complex z, t_complex c, int max_iter) 
{
    int iter = 0;
    while (z.real * z.real + z.unreal * z.unreal <= 4 && iter < max_iter)
	{
        double temp = z.real * z.real - z.unreal * z.unreal + c.real;
        z.unreal = 2 * z.real * z.unreal + c.unreal;
        z.real = temp;
        iter++;
    }
    return iter;
}

void	ft_render_fractal(t_fractol *fractol)
{
	int			x;
	int			y;
	int			color;
	t_complex	c;
	t_complex juliaC;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = ft_pixel_to_complexnumber(x, y, fractol);
			if (ft_strncmp(fractol->name, "julia", 5) == 0)
			{
				juliaC = ft_pixel_to_complexnumber(fractol->julia_x, fractol->julia_y, fractol);
                color = ft_get_color(ft_julia(c, juliaC, MAX_ITER));
			}
			else
				color = ft_get_color(ft_mandelbrot(c, MAX_ITER));
			mlx_pixel_put(fractol->mlx, fractol->window, x, y, color);
			x++;
		}
		y++;
	}
}

