/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:12:24 by tbornema          #+#    #+#             */
/*   Updated: 2023/02/10 11:30:44 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_substr_count(char const *str, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*get_substr(char *substr, char const *s, int i, int substr_len)
{
	int	j;

	j = 0;
	while (substr_len > 0)
	{
		substr[j] = s[i - substr_len];
		j++;
		substr_len--;
	}
	substr[j] = '\0';
	return (substr);
}

static char	**alloc_substr(char const *s, char c, char **splitarr, size_t count)
{
	size_t	substr;
	int		i;
	int		substr_len;

	i = 0;
	substr = 0;
	substr_len = 0;
	while (substr < count)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			substr_len++;
		}
		splitarr[substr] = (char *)malloc(sizeof(char) * (substr_len + 1));
		if (!splitarr)
			return (NULL);
		get_substr(splitarr[substr], s, i, substr_len);
		substr_len = 0;
		substr++;
	}
	splitarr[substr] = NULL;
	return (splitarr);
}

char	**ft_split(char const *s, char c)
{
	char	**splitarr;
	size_t	count;

	if (!s)
		return (NULL);
	count = get_substr_count(s, c);
	splitarr = malloc(sizeof(*splitarr) * (count + 1));
	if (!splitarr)
		return (NULL);
	splitarr = alloc_substr(s, c, splitarr, count);
	return (splitarr);
}
