/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:38:25 by tbornema          #+#    #+#             */
/*   Updated: 2023/10/12 12:17:01 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

int	ft_strisalnum(char	*str)
{
	int	x;
	
	x = 0;
	while (str[x] != '\0')
	{
		if (!ft_isdigit((int)str[x]))
			return (0);
		x++;
	}
	return (1);
}