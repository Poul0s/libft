/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:12:26 by psalame           #+#    #+#             */
/*   Updated: 2023/10/31 12:09:46 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	if (s == NULL)
		return (s);
	i = 0;
	while (i < n)
		((int *)s)[i++] = c;
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL && n != 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (i < n)
	{
		if (p1 != p2)
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
