/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlowint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:48:33 by tbornema          #+#    #+#             */
/*   Updated: 2023/09/14 13:36:14 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_getlowint(int *array, int *count)
{
	int	i;
	int	min;

	min = array[0];
	i = 1;
	while (i < *count)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);		
}