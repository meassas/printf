/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:29:21 by meassas           #+#    #+#             */
/*   Updated: 2017/09/03 12:11:41 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		print_char(t_format *format, char str)
{
	ft_putchar(str);
	format->ret++;
}

void		printf_char_right(t_format *format, t_conversion *conversion, char nb)
{
	char	*str;
	char	c;

	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	if (conversion->flags.pad_with_zeros)
		c = '0';
	else
		c = ' ';
	if (conversion->width)
		conversion->get_precision = 0;
	str = ft_itoa_base(nb, 10);
	add_width_zeros(c, 1, format, conversion);
	add_width_spaces(c, 1, format, conversion);
	print_char(format, nb);
}

void		printf_char_left(t_format *format, t_conversion *conversion, char nb)
{
	char				*str;
	unsigned int		i;

	str = ft_itoa_base(nb, 10);
	i = 1;
	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	print_char(format, nb);
	while (i < conversion->width)
	{
		ft_putchar(' ');
		i++;
		format->ret++;
	}
}

void		handle_char(t_format *format, t_conversion *conversion, char nb)
{
	if (conversion->flags.left_justifier)
		printf_char_left(format, conversion, nb);
	else
		printf_char_right(format, conversion, nb);
}
