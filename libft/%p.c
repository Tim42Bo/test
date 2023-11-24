/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %p.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:06:00 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/05 08:06:00 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handle_pointer(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == NULL)
	{
		ft_handle_null_pointer();
		return (5);
	}
	else
	{
		len = ft_handle_non_null_pointer(ptr);
		return (len);
	}
}
