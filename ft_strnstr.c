/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:48:02 by psalame           #+#    #+#             */
/*   Updated: 2023/10/31 12:48:13 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		if (big[i] == *little)
		{
			j = 0;
			while (j < len && big[i + j] == little[j] && little[j] != 0)
				j++;
			if (big[i + j] == little[j] || little[j] == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
