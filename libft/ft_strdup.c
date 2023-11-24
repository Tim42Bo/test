/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 05:08:31 by tbornema          #+#    #+#             */
/*   Updated: 2023/09/07 16:07:47 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)

{
	char	*copy;
	size_t	len;

	len = ft_strlen(s1) + 1;
	copy = (char *)malloc(sizeof(*copy) * len);
	if (!copy)
		return (NULL);
	return ((char *)ft_memcpy(copy, s1, len));
}
