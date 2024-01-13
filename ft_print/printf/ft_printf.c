/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:14:26 by psalame           #+#    #+#             */
/*   Updated: 2024/01/13 10:57:19 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_Int.h"

static void	ft_printf_err(const char *str,
						int *i,
						int *writted_char,
						t_print_format *data)
{
	int	j;

	j = data->j;
	if (str[j] == 0 || data->field_width == -1 || data->precision_width == -1)
	{
		*writted_char = -1;
		*i = ft_strlen(str);
	}
	else
	{
		ft_putchar_fd('%', 1);
		*i = *i + 1;
		*writted_char += 1;
	}
}

static void	ft_formatf(const char *str, int *i, int *writted_char, va_list ap)
{
	t_print_format	data;
	int				j;

	ft_bzero(&data, sizeof(data));
	j = *i + 1;
	while (!data.error && data.conversion == NULL && str[j])
	{
		if (ft_is_combinaison_flag(str[j]))
			ft_parse_combinaison_flag(str, &data, &j, ap);
		else if (ft_is_conversion_flag(str[j]))
			ft_parse_conversion_flag(str[j], &j, &data);
		else
			data.error = true;
	}
	data.j = j;
	if (!data.flag || data.error)
		ft_printf_err(str, i, writted_char, &data);
	else
	{
		*writted_char = *writted_char + (*data.conversion)(&data, ap);
		*i = j;
	}
}

int	ft_printf(const char *str, ...)
{
	int		writted_char;
	int		i;
	int		to_write;
	va_list	ap;

	va_start(ap, str);
	writted_char = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_formatf(str, &i, &writted_char, ap);
		else
		{
			to_write = 0;
			while (str[i + to_write] != '\0' && str[i + to_write] != '%')
				to_write++;
			write(1, str + i, to_write);
			writted_char += to_write;
			i += to_write;
		}
	}
	va_end(ap);
	return (writted_char);
}
