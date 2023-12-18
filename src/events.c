/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:57:39 by tbornema          #+#    #+#             */
/*   Updated: 2023/12/14 13:24:54 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h> //REMOVE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int	ft_mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4 || button == 5)
	{
		if (button == 4)
			fractol->zoom *= 1.1; //zoom in
		if (button == 5)
			fractol->zoom *= 0.9; //zoom out

	}
	printf("ZOOM-LVL in Mousehook: %.20f\n", fractol->zoom);
	ft_render_fractal(fractol);
	return (0);
}

int ft_quit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx,	fractol->imgage.img_ptr);
	mlx_destroy_window(fractol->mlx,fractol->window);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(0);
}

int ft_key_hook(int keycode, t_fractol *fractol)
{
	double	move;
	ft_printf("Keycode: %d\n", keycode);	
	if (keycode == 65307) // ESC
    {
        ft_quit(fractol);
    }
	move = 50;
    if (keycode == 65361) //Left
        fractol->center.real -= move * fractol->zoom;
    else if (keycode == 65363) //Right
        fractol->center.real += move * fractol->zoom;
    else if (keycode == 65362) //Up
        fractol->center.unreal -= move * fractol->zoom;
    else if (keycode == 65364) //Down
        fractol->center.unreal += move * fractol->zoom;
	printf("ZOOM-LVL in Keyhook: %.20f\n", fractol->zoom);
	ft_render_fractal(fractol);
    return (0);
}

