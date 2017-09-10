/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 12:12:04 by meassas           #+#    #+#             */
/*   Updated: 2017/09/03 12:12:12 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		handle_flag_hashtag(t_format *format, t_conversion *conversion)
{
	if (conversion->flags.hashtag && conversion->precision && conversion->get_precision != 0)
	{
		ft_putchar('0');
		format->ret++;
	}
}

static void		print_octal(t_format *format, char *str)
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

void		printf_octal_right(t_format *format, t_conversion *conversion, uintmax_t nb)
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
	str = ft_itoab_uintmax(nb, 8);
	length = ((int)ft_strlen(str) < conversion->get_precision) ? conversion->get_precision : ft_strlen(str);
	add_width_zeros(c, length, format, conversion);
	add_width_spaces(c, length, format, conversion);
	handle_flag_hashtag(format, conversion);
	precision_zeros(format, conversion, str);
	print_octal(format, str);
}

void		printf_octal_left(t_format *format, t_conversion *conversion, uintmax_t nb)
{
	char	*str;
	unsigned int		i;
	int		length;

	str = ft_itoab_uintmax(nb, 8);
	i = ft_strlen(str);
	length = (int)ft_strlen(str) < conversion->get_precision ? conversion->get_precision : ft_strlen(str);
	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	print_octal(format, str);
	while (i < conversion->width)
	{
		ft_putchar(' ');
		i++;
		format->ret++;
	}
}

void		handle_octal(t_format *format, t_conversion *conversion, uintmax_t nb)
{
	if (conversion->flags.left_justifier && !conversion->precision)
		printf_octal_left(format, conversion, nb);
	else
		printf_octal_right(format, conversion, nb);
}
