/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:15:24 by meassas           #+#    #+#             */
/*   Updated: 2017/07/27 18:37:52 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		handle_flag_hashtag(t_format *format, t_conversion *conversion)
{
	if (conversion->flags.hashtag && conversion->precision && conversion->get_precision != 0)
	{
		if (conversion->length == L)
		{
			ft_putstr("0X");
			format->ret += 2;
		}
		else
		{
			ft_putstr("0x");
			format->ret += 2;
		}
	}
}

static void		print_hex(t_format *format, t_conversion *conversion, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (conversion->length == L)
		{
			ft_putchar(ft_toupper(str[i]));
			i++;
			format->ret++;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
			format->ret++;
		}
	}
}

void		printf_hexa_right(t_format *format, t_conversion *conversion, uintmax_t nb)
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
	str = ft_itoab_uintmax(nb, 16);
	length = ((int)ft_strlen(str) < conversion->get_precision) ? conversion->get_precision : ft_strlen(str);
	add_width_zeros(c, length, format, conversion);
	add_width_spaces(c, length, format, conversion);
	handle_flag_hashtag(format, conversion);
	//precision_zeros(format, conversion, str);
	print_hex(format, conversion, str);
}

void		printf_hexa_left(t_format *format, t_conversion *conversion, uintmax_t nb)
{
	char	*str;
	unsigned int		i;
	int		length;

	str = ft_itoab_uintmax(nb, 16);
	i = ft_strlen(str);
	length = (int)ft_strlen(str) < conversion->get_precision ? conversion->get_precision : ft_strlen(str);
	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	handle_flag_hashtag(format, conversion);
	print_hex(format, conversion, str);
	while (i < conversion->width)
	{
		ft_putchar(' ');
		i++;
		format->ret++;
	}
	precision_zeros(format, conversion, str);
}

void		handle_hex(t_format *format, t_conversion *conversion, uintmax_t nb)
{
	if (conversion->flags.left_justifier)
		printf_hexa_left(format, conversion, nb);
	else
		printf_hexa_right(format, conversion, nb);
}
