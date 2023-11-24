/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countarray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:52:31 by tbornema          #+#    #+#             */
/*   Updated: 2023/09/08 10:57:43 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countarray(char **array)
{
	int	count;
	int	i;
	
	count = 0;
	i = 0;
	while (array[i] != NULL)
	{
		count++;
		i++;
	}
	return (count);
}
