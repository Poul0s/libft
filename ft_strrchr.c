/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:50:56 by psalame           #+#    #+#             */
/*   Updated: 2023/10/31 12:51:04 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last_occ;

	if (s == NULL)
		return (NULL);
	i = 0;
	last_occ = NULL;
	while (s[i] != 0)
	{
		if (s[i] == c)
			last_occ = (char *)s + i;
		i++;
	}
	if (c == 0)
		last_occ = (char *)s + i;
	return (last_occ);
}
