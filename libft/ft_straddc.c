/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:37:33 by tbornema          #+#    #+#             */
/*   Updated: 2023/10/12 13:05:56 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddc(char *str, char c)
{
	int		len;
	char	*tmp;

	if (!str)
	{
		tmp = (char *)malloc(2 * sizeof(char));
		if (!tmp)
			return (NULL);
		tmp[0] = c;
		tmp[1] = '\0';
		return (tmp);
	}
	len = ft_strlen(str);
	tmp = ft_safeinitcharstrplus(str, 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, str, len + 1);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	free(str);
	return (tmp);
}