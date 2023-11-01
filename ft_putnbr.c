/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:37:59 by psalame           #+#    #+#             */
/*   Updated: 2023/11/01 13:33:02 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		un = -n;
	}
	else
		un = n;
	if (un > 9)
		ft_putnbr_fd(un / 10, fd);
	c = un % 10 + '0';
	write(fd, &c, 1);
}
