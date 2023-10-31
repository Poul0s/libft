/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:44:22 by psalame           #+#    #+#             */
/*   Updated: 2023/10/31 12:45:08 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	int		*ptr;

	if (s == NULL)
		return (NULL);
	i = 0;
	ptr = (int *)s;
	while (i < n && ptr[i] != c)
		i++;
	if (ptr[i] == c)
		return (ptr + i);
	return (NULL);
}
