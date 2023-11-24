/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safecharstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:02:08 by tbornema          #+#    #+#             */
/*   Updated: 2023/10/12 12:44:07 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_safecharstr(char	*str)
{
	char	*newstr;
	size_t	len;

	if (str == NULL)
	return NULL;
	len = ft_strlen(str);
	newstr = ft_calloc(len + 1, sizeof(char ));
	if (newstr)
	{
		ft_strncpy(newstr, str, len);
		newstr[len] = '\0';
	}
	return (newstr);
}

char 	*ft_safeinitcharstr(char 	*str)
{
	char 	*newstr;
	size_t	len;

	len = ft_strlen(str);
	newstr = ft_calloc(len + 1, sizeof(char ));
	return (newstr);
}

char 	*ft_safeinitcharstrplus(char *str, int n)
{
	char 	*newstr;
	size_t	len;

	len = ft_strlen(str);
	newstr = ft_calloc(len + 1 + n, sizeof(char ));
	return (newstr);
}

/* char 	**ft_safechararray(char  **argv)
{
	char 	**safearray;
	int		i;
	int		j;
	int		a;
	int		size;

	size = ft_countarray(argv);
	if (argv ==NULL || size <0)
		return NULL;
	safearray = malloc(size * sizeof(char  *));
	if (safearray == NULL)
		return NULL;
	i = 0;
	a = 1;
	while (i < size - 1)
	{
		safearray[i] = ft_safecharstr(argv[a]);
			if (safearray[i] == NULL)
			{
				j = 0;
				while (j < i)
				{
					free(safearray[j]);
					j++;
				}
				free(safearray);
				return NULL;
			}
		i++;
		a++;
	}
	return(safearray);
} */

char 	**ft_safeinitchararray(char  size)
{
	char 	**initarray;
	int		i;

	if (size <= 0)
		return NULL;
	initarray = malloc(size *sizeof(char  *));
	if (initarray == NULL)
		return NULL;
	i = 0;
	while (i < size)
	{
		initarray[i] = NULL;
		i++;
	}
	return (initarray);
}

void	ft_freechararray(char  **array)
{
	int	i;
	int	size;
	
	size = ft_countarray(array);
	i = 0;
	if (array == NULL)
		return ;
	while (i <size)
	{
		free(array[i]);
		i++;
	}
}