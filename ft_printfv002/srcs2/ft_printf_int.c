/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 12:11:01 by meassas           #+#    #+#             */
/*   Updated: 2017/09/10 19:31:38 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_plus_or_space(t_format *format, t_conversion *conversion)
{
	if (!conversion->negative && conversion->specifier == SIGNED_DECIMAL)
	{
		if (conversion->flags.sign_justifier)
		{
			ft_putchar('+');
			format->ret++;
		}
		else if (conversion->flags.pad_with_blank)
		{
			ft_putchar(' ');
			format->ret++;
		}
	}
}

static void	print_putnbr_after_width(t_format *format, char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
		format->ret++;
	}
}

void		ft_putnbr_right(t_format *format, t_conversion *conversion, int neg, uintmax_t nb)
{
	size_t			length;
	char			*str;
	char			c;

	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	if (conversion->flags.pad_with_zeros)
		c = '0';
	else
		c = ' ';
	str = ft_itoab_uintmax(nb, 10);
	length = ((int)ft_strlen(str) < conversion->get_precision) ? conversion->get_precision : ft_strlen(str);
	if (conversion->flags.sign_justifier || conversion->flags.pad_with_blank)
		length += 1;
	add_width_zeros(c, length, format, conversion);
	add_width_spaces(c, length, format, conversion);
	add_plus_or_space(format, conversion);
	if (neg == 1)
		ft_putchar('-');
	precision_zeros(format, conversion, str);
	print_putnbr_after_width(format, str);
}

void		ft_putnbr_left(t_format *format, t_conversion *conversion, uintmax_t nb)
{
	size_t			i;
	char			*str;

	i = 0;
	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	str = ft_itoab_uintmax(nb, 10);
	add_plus_or_space(format, conversion);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
		format->ret++;
	}
	if (conversion->negative)
		i += 1;
	while (i < conversion->width)
	{
		ft_putchar(' ');
		i++;
		format->ret++;
	}
}
