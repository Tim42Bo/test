/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safestr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:48:17 by tbornema          #+#    #+#             */
/*   Updated: 2023/09/14 14:06:56 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_safestr(int	*str, int len)
{
	int	*newstr;

	if (!str)
		return NULL;
	newstr = ft_calloc(len + 1, sizeof(int));
	if (newstr)
	{
		ft_strnintcpy(newstr, str, len);
		newstr[len] = '\0';
	}
	return (newstr);
}

int	*ft_safeinitstr(int len)
{
	int	*newstr;
	
	newstr = ft_calloc(len + 1, sizeof(int));
	return (newstr);
}

int	**ft_safearray(int **argv, int size)
{
	int	**safearray;
	int		i;
	int		j;

	if (argv ==NULL || size <0)
		return NULL;
	safearray = malloc(size * sizeof(int *));
	if (safearray == NULL)
		return NULL;
	i = 0;
	while (i < size)
	{
		safearray[i] = ft_safestr(argv[i], size);
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
	}
	return(safearray);
}

int	**ft_safeinitarray(int size)
{
	int	**initarray;
	int		i;

	if (size <= 0)
		return NULL;
	initarray = malloc(size * sizeof(int *));
	if (initarray == NULL)
		return NULL;
	i = 0;
	while (i < size)
	{
		initarray[i] = ft_calloc(sizeof(int), 1);
		initarray[i][0] = 0;
		ft_printf("allocated, %d\n", initarray[i]);
		i++;
	}
	return (initarray);
}

void	ft_freearray(int **array, int count)
{
	int	i;
	
	i = 0;
	if (array == NULL)
		return ;
	while (i <count)
	{
		free(array[i]);
		i++;
	}
}