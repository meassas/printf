/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:01:54 by meassas           #+#    #+#             */
/*   Updated: 2017/08/07 15:13:49 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		handle_pointer(t_format *format)
{
		ft_putstr("0x10");
		format->ret += 4;
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
		return ;
	c = ' ';
	str = ft_itoab_uintmax((int)nb, 16);
	length = ft_strlen(str);
	add_width_zeros(c, length, format, conversion);
	add_width_spaces(c, length, format, conversion);
	handle_pointer(format);
	print_pointer(format, str);
	free(str);
}

static void		printf_pointer_left(t_format *format, t_conversion *conversion, void *nb)
{
	char	*str;
	unsigned int		length;

	str = ft_itoab_uintmax((int)nb, 16);
	//i = ft_strlen(str);
	length = ft_strlen(str);
	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	handle_pointer(format);
	print_pointer(format, str);
	while (length <= conversion->width)
	{
		ft_putchar(' ');
		length++;
		format->ret++;
	}
	free(str);
}

void		handle_flags_pointer(t_format *format, t_conversion *conversion, void *nb)
{
	if (conversion->flags.left_justifier)
		printf_pointer_right(format, conversion, nb);
	else
		printf_pointer_left(format, conversion, nb);
}
