/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:51:37 by psalame           #+#    #+#             */
/*   Updated: 2023/10/31 10:51:54 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	real_len;
	char	*sub;

	if (s == NULL || start >= ft_strlen((char *)s))
		return (NULL);
	real_len = ft_strlen((char *)s + start);
	if (len < real_len)
		real_len = len;
	sub = malloc((real_len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (((char *)s)[start + i] && i < real_len)
	{
		sub[i] = s[start + i];
	}
	sub[i] = 0;
	return (sub);
}
