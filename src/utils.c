/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:31:28 by tbornema          #+#    #+#             */
/*   Updated: 2023/11/24 13:35:11 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_get_color(int iter)
{
	if (iter == MAX_ITER)
		return (BLACK);
	return (WHITE);
}

t_complex	ft_pixel_to_complexnumber(int x, int y)
{
	t_complex	c;
	
	c.real = (double)x / WIDTH * 4 - 2;
	c.unreal = (double)y / HEIGHT * 4 - 2;
	return (c);
}