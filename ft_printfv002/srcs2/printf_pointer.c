/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:01:54 by meassas           #+#    #+#             */
/*   Updated: 2017/09/03 12:12:25 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		is_pointer(t_format *format)
{
		ft_putstr("0x");
		format->ret += 2;
}

static void		print_pointer(t_format *format, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i++]);
		format->ret++;
	}
}

static void		printf_pointer_right(t_format *format, t_conversion *conversion, void* nb)
{
	char	*str;
	int		length;
	char	c;

	if (conversion->precision)
		c = '0';
	else
		c = ' ';
	str = ft_itoab_uintmax((uintmax_t)nb, 16);
	length = (int)ft_strlen(str) < conversion->get_precision ? conversion->get_precision : (int)ft_strlen(str);
	add_width_zeros(c, length, format, conversion);
	add_width_spaces(c, length, format, conversion);
	is_pointer(format);
	precision_zeros(format, conversion, str);
	print_pointer(format, str);
}

static void		printf_pointer_left(t_format *format, t_conversion *conversion, void *nb)
{
	char	*str;
	unsigned int		length;
	char c;

	if (conversion->precision)
		c = '0';
	str = ft_itoab_uintmax((uintmax_t)nb, 16);
	length = (int)ft_strlen(str) < conversion->get_precision ? conversion->get_precision : (int)ft_strlen(str);
	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	is_pointer(format);
	add_width_zeros(c, length, format, conversion);
	//add_width_spaces(c, length, format, conversion);
	precision_zeros(format, conversion, str);
	print_pointer(format, str);
	while (length + 2 < conversion->width)
	{
		ft_putchar(' ');
		length++;
		format->ret++;
	}
}

void		handle_pointer(t_format *format, t_conversion *conversion, void *nb)
{
	if (conversion->flags.left_justifier)
		printf_pointer_left(format, conversion, nb);
	else
		printf_pointer_right(format, conversion, nb);
}
