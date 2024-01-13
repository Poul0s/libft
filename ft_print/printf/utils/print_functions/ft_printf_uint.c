/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:51:47 by psalame           #+#    #+#             */
/*   Updated: 2024/01/13 11:15:12 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_Int.h"

static int	ft_get_uint_size(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		size = 1;
	while (nb != 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static void	ft_print_padding(t_print_format *data, int *writted)
{
	ft_putchar_rep(' ', data->field_width - *writted);
	if (data->field_width > *writted)
		*writted += (data->field_width - *writted);
}

void	ft_putunbr_size(unsigned int nb, int precision)
{
	static int	current_width = 0;
	char		c;

	current_width++;
	c = '0' + nb % 10;
	if (nb / 10 != 0)
		ft_putunbr_size(nb / 10, precision);
	else
	{
		while (current_width++ < precision)
			write(1, "0", 1);
		current_width = 0;
	}
	write(1, &c, 1);
}

int	ft_printf_uint(t_print_format *data, va_list ap)
{
	unsigned int	value;
	int				writted;

	value = va_arg(ap, unsigned int);
	writted = ft_get_uint_size(value);
	if (!data->precision && data->padding_left)
	{
		data->precision_width = data->field_width;
		data->precision = true;
	}
	if (data->precision && (data->precision_width > writted || value == 0))
		writted = data->precision_width;
	if (!data->padding_right)
		ft_print_padding(data, &writted);
	if (!data->precision || (data->precision_width > 0 || value != 0))
		ft_putunbr_size(value, data->precision_width);
	if (data->padding_right)
		ft_print_padding(data, &writted);
	return (writted);
}
