/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:13:23 by tbornema          #+#    #+#             */
/*   Updated: 2023/02/09 13:13:23 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischars(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)

{
	char	*cpystr;
	size_t	i;
	size_t	j;
	size_t	end;

	i = 0;
	j = 0;
	end = ft_strlen(s1);
	while (s1[i] != '\0' && ft_ischars(s1[i], set))
		i++;
	while (s1[i] != '\0' && ft_ischars(s1[end -1], set))
		end--;
	cpystr = (char *)malloc((end - i + 1) * sizeof(*s1));
	if (!cpystr)
		return (NULL);
	while (i < end)
	{
		cpystr[j] = s1[i];
		j++;
		i++;
	}
	cpystr[j] = '\0';
	return (cpystr);
}
