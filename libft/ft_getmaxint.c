/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmaxint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:41:58 by tbornema          #+#    #+#             */
/*   Updated: 2023/09/14 13:36:04 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getmaxint(int *array, int *count)
{
	int	i;
	int	max;

	max = array[0];
	i = 1;
	while (i < *count)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);		
}