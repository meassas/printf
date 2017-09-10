/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:15:24 by meassas           #+#    #+#             */
/*   Updated: 2017/09/10 19:58:29 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		handle_flag_hashtag(t_format *format, t_conversion *conversion, int nb)
{
	if (conversion->flags.hashtag && !conversion->get_precision && nb != 0)
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

	if (nb == 0 && !conversion->precision && conversion->get_precision == 0)
	{
		ft_putchar('0');
		format->ret++;
		//ft_putstr("je passe ici");
		return ;
	}
	if (conversion->flags.pad_with_zeros)
		c = '0';
	else
		c = ' ';
	str = ft_itoab_uintmax(nb, 16);
	length = ((int)ft_strlen(str) < conversion->get_precision) ? conversion->get_precision : ft_strlen(str);
	add_width_spaces(c, length, format, conversion);
	handle_flag_hashtag(format, conversion, nb);
	add_width_zeros(c, length, format, conversion);
	//if (nb == 0 && (format->ret += 1) && conversion->get_precision != 0)
	//	ft_putchar('0');
	precision_zeros(format, conversion, str);
	print_hex(format, conversion, str);
}

void		printf_hexa_left(t_format *format, t_conversion *conversion, uintmax_t nb)
{
	char	*str;
	unsigned int		i;
	int		length;

	if (nb == 0 && (format->ret += 1))
		ft_putchar('0');
	if (nb == 0 && conversion->precision && conversion->get_precision == 0)
		return ;
	str = ft_itoab_uintmax(nb, 16);
	i = ft_strlen(str);
	length = (int)ft_strlen(str) < conversion->get_precision ? conversion->get_precision : ft_strlen(str);
	handle_flag_hashtag(format, conversion, nb);
	precision_zeros(format, conversion, str);
	print_hex(format, conversion, str);
	if (conversion->precision)
		conversion->width = 0;
	if (conversion->flags.hashtag)
		conversion->width -= 2;
	while (i < conversion->width)
	{
		ft_putchar(' ');
		i++;
		format->ret++;
	}
}

void		handle_hex(t_format *format, t_conversion *conversion, uintmax_t nb)
{
	if (conversion->flags.left_justifier)
		printf_hexa_left(format, conversion, nb);
	else
		printf_hexa_right(format, conversion, nb);
}

/*int		main(int ac, char **av)
{
	t_format format;
	t_conversion conversion;

	format.string = "%x\n";
	conversion.specifier = 0;
	printf_hexa_right(&format, &conversion, 0);
}*/
