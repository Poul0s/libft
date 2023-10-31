/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:32:27 by psalame           #+#    #+#             */
/*   Updated: 2023/10/30 15:56:56 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

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
