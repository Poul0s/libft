/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:47:25 by psalame           #+#    #+#             */
/*   Updated: 2023/10/31 12:50:08 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*copy;

	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	i = 0;
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (copy);
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = i;
	return (copy);
}
