/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:01:46 by tbornema          #+#    #+#             */
/*   Updated: 2023/11/27 16:53:35 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		++i;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		++i;
	}
	return (sign * result);
}

double	ft_atod(const char *nptr)
{
	size_t	i;
	int		sign;
	double	result;
	double	factor;

	i = 0;
	result = 0.0;
	sign = 1;
	factor = 1.0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		++i;
	}
	while (('0' <= nptr[i] && nptr[i] <= '9') || nptr[i] == '.')
	{
		if (nptr[i] == '.')
		{
			i++;
			while ('0' <= nptr[i] && nptr[i] <= '9')
			{
				factor /= 10.0;
				result += (nptr[i] - '0') * factor;
				++i;
			}
			break;
		}
		result = result * 10.0 + (nptr[i] - '0');
		++i;
	}
	return (sign * result);
}
