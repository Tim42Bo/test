/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 06:29:16 by honeybadger       #+#    #+#             */
/*   Updated: 2023/02/10 11:52:45 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	*y;

	i = 0;
	y = (char *)s;
	while (y[i] != '\0')
	{
		if (y[i] == (char)c)
			return ((char *)&y[i]);
		i++;
	}
	if (y[i] == (char)c)
		return ((char *)&y[i]);
	return (NULL);
}
