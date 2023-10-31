/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:04 by psalame           #+#    #+#             */
/*   Updated: 2023/10/31 10:49:18 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		res;

	if (nptr == NULL)
		return (0);
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	res = 0;
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

static int	ft_intlen(int n)
{
	size_t			len;
	unsigned int	un;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		un = -n;
		len++;
	}
	else
		un = n;
	while (un > 0)
	{
		len++;
		un = un / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	size_t			len;
	unsigned int	un;
	size_t			i;

	len = ft_intlen(n);
	res = malloc((len + 1) * sizeof(char));
	i = len;
	res[i--] = 0;
	if (n < 0)
	{
		un = -n;
		res[i++] = '-';
	}
	else
		un = n;
	while (un > 9)
	{
		res[i--] = '0' + un % 10;
		un /= 10;
	}
	res[i--] = '0' + un % 10;
	return (res);
}
