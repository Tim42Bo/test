/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:31:28 by tbornema          #+#    #+#             */
/*   Updated: 2023/11/27 16:22:20 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_get_color(int depth)
{
	int	colors[NUMCOLORS] = {
		0x000000, 0xFFFFFF, 0xFF0000, 0x00FF00, 0x0000FF,
		0xFF00FF, 0xCCFF00, 0xFF6600, 0x660066, 0x33CCCC,
		0xFF66B2, 0x0066FF, 0xFF3300, 0xFF5733, 0xFFD700,
		0x50C878, 0x87CEEB, 0x7851A9, 0xFFB7C5, 0x40E0D0,
		0x191970, 0xFFBF00, 0x708090
	};
	int	index;
	index = (depth + (depth * depth) % NUMCOLORS) % NUMCOLORS;
	return (colors[index]);
}

t_complex	ft_pixel_to_complexnumber(int x, int y, t_fractol *fractol)
{
	t_complex	c;
	
	c.real = (x - WIDTH / 2) * fractol->zoom + fractol->center.real;
    c.unreal = (y - HEIGHT / 2) * fractol->zoom + fractol->center.unreal;
	return (c);
}

