/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:07:37 by meassas           #+#    #+#             */
/*   Updated: 2017/08/05 17:03:06 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		handle_neg_signed_int(t_conversion *conversion, t_format *format, intmax_t nb)
{
	int		neg;

	neg = 0;
	if (nb < 0)
	{
		if (conversion->width && !conversion->flags.left_justifier &&
				!conversion->flags.pad_with_zeros)
		{
			nb *= -1;
			format->ret++;
			neg = 1;
		}
		else
		{
			ft_putchar('-');
			nb *= -1;
			format->ret++;
		}
		conversion->negative = 1;
	}
	if (conversion->flags.left_justifier && !conversion->precision)
		ft_putnbr_left(format, conversion, nb);
	else
		ft_putnbr_right(format, conversion, neg, nb);
}

void		printf_signed_int(t_format *format, t_conversion *conversion, va_list arguments)
{
	intmax_t	arg;

	if (conversion->length == HH)
		arg = va_arg(arguments, int);
	else if (conversion->length == H)
		arg = (short int)va_arg(arguments, int);
	else if (conversion->length == L)
		arg = va_arg(arguments, long);
	else if (conversion->length == LL)
		arg = va_arg(arguments, long long);
	else if (conversion->length == J)
		arg = va_arg(arguments, intmax_t);
	else if (conversion->length == Z)
		arg = va_arg(arguments, size_t);
	else
		arg = va_arg(arguments, int);
	handle_neg_signed_int(conversion, format, arg);
}

void		printf_unsigned_int(t_format *format, t_conversion *conversion, va_list arguments)
{
	uintmax_t	arg;

	if (conversion->length == HH)
		arg = va_arg(arguments, int);
	else if (conversion->length == H)
		arg = (unsigned short int)va_arg(arguments, int);
	else if (conversion->length == L)
		arg = va_arg(arguments, unsigned long int);
	else if (conversion->length == LL)
		arg = va_arg(arguments, unsigned long long int);
	else if (conversion->length == J)
		arg = va_arg(arguments, uintmax_t);
	else if (conversion->length == Z)
		arg = va_arg(arguments, ssize_t);
	else
		arg = va_arg(arguments, unsigned int);
	if (conversion->flags.left_justifier)
		ft_putnbr_left(format, conversion, arg);
	else
		ft_putnbr_right(format, conversion, 0, arg);
}

void		print_type(t_format *format, t_conversion *conversion, va_list arguments)
{
	if (conversion->specifier == SIGNED_DECIMAL)
		printf_signed_int(format, conversion, arguments);
	else if (conversion->specifier == UNSIGNED_DECIMAL)
		printf_unsigned_int(format, conversion, arguments);
	else if (conversion->specifier == HEX)
		handle_hex(format, conversion, va_arg(arguments, unsigned int));
	else if (conversion->specifier == OCTAL)
		handle_octal(format, conversion, va_arg(arguments, unsigned int));
	else if (conversion->specifier == POINTER)
		handle_flags_pointer(format, conversion, va_arg(arguments, void*));
}
