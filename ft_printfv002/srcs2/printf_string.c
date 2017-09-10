/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:19:56 by meassas           #+#    #+#             */
/*   Updated: 2017/09/03 12:12:37 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		print_string(t_format *format, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
			ft_putchar(str[i]);
			i++;
			format->ret++;
	}
}

void		printf_string_right(t_format *format, t_conversion *conversion, void* nb)
{
	char	*str;
	int		length;
	char	c;

	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	if (conversion->flags.pad_with_zeros)
		c = '0';
	else
		c = ' ';
	if (conversion->width)
		conversion->get_precision = 0;
	str = nb;
	length = ((int)ft_strlen(str) < conversion->get_precision) ? conversion->get_precision : ft_strlen(str);
	add_width_zeros(c, length, format, conversion);
	add_width_spaces(c, length, format, conversion);
	precision_zeros(format, conversion, str);
	print_string(format, str);
}

void		printf_string_left(t_format *format, t_conversion *conversion, void* nb)
{
	char	*str;
	unsigned int		i;
	int		length;

	str = nb;
	i = ft_strlen(str);
	length = (int)ft_strlen(str) < conversion->get_precision ? conversion->get_precision : ft_strlen(str);
	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	print_string(format, str);
	while (i < conversion->width)
	{
		ft_putchar(' ');
		i++;
		format->ret++;
	}
}

void		handle_string(t_format *format, t_conversion *conversion, void* nb)
{
	if (conversion->flags.left_justifier)
		printf_string_left(format, conversion, nb);
	else
		printf_string_right(format, conversion, nb);
}
