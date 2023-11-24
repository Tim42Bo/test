/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:32:13 by tbornema          #+#    #+#             */
/*   Updated: 2023/02/09 13:32:13 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_allocarr(char **str, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i = 1;
	while (n < -9 || n > 9)
	{
		n = n / 10;
		i++;
	}
	*str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	(*str)[i + 1] = '\0';
	return (i + 1);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	int		j;
	char	*str;

	j = ft_allocarr(&str, n);
	if (!j)
		return (NULL);
	while (n < -9 || n > 9)
	{
		str[j - 1] = ft_abs(n % 10) + 48;
		n = n / 10;
		j--;
	}
	str[j - 1] = ft_abs(n % 10) + 48;
	if (n < 0)
		str[0] = '-';
	return (str);
}
