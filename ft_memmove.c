/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:44:48 by psalame           #+#    #+#             */
/*   Updated: 2023/10/31 12:45:10 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		overlap;

	if (dest == NULL || src == NULL)
		return (dest);
	if (src < dest)
	{
		overlap = 1;
		i = n;
	}
	else
	{
		overlap = 0;
		i = 0;
	}
	while ((overlap == 1 && i > 0) || (overlap == 0 && i < n))
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		if (overlap == 1)
			i--;
		else
			i++;
	}
	return (dest);
}
