/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 07:54:24 by honeybadger       #+#    #+#             */
/*   Updated: 2023/02/10 11:41:25 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int character)
{
	char	*searchitem;

	searchitem = NULL;
	while (*s != '\0')
	{
		if (*s == (char)character)
			searchitem = ((char *)s);
		s++;
	}
	if (*s == (char)character)
		searchitem = ((char *)s);
	return ((char *)searchitem);
}
