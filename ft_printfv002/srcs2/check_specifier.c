/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 12:09:46 by meassas           #+#    #+#             */
/*   Updated: 2017/09/10 19:49:03 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		parse_invalide_specifier(t_format *format)
{
	char c;

	c = format->string[format->cur];
	if (ft_isprint(c))
		if (ft_isdigit(c) || c == '#' || c == ' ' || c == '+' || c == '-' || c == '.')
			return (1);
	return (0);
}

static int		parse_valide_specifier(t_format *format, t_conversion *conversion)
{
	char c;

	c = format->string[format->cur];
	//ft_putstr("c = ");
	//ft_putchar(c);
	if (c == 'd' || c == 'D' || c == 'i')
		conversion->specifier = SIGNED_DECIMAL;
	else if (c == 'u' || c == 'U')
		conversion->specifier = UNSIGNED_DECIMAL;
	else if (c == 'o' || c == 'O')
		conversion->specifier = OCTAL;
	else if (c == 'x' || c == 'X')
		conversion->specifier = HEX;
	else if (c == 'c' || c == 'C')
		conversion->specifier = CHAR;
	else if (c == 's' || c == 'S')
		conversion->specifier = STRING;
	else if (c == 'p')
		conversion->specifier = POINTER;
	else
		return (0);
	return (1);
}

static void		parse_upper_specifier(t_format *format, t_conversion *conversion)
{
	char c;

	c = format->string[format->cur];
	if (c == 'C' || c == 'D' || c == 'S' || c == 'O' || c == 'U' || c == 'X')
		conversion->length = L;
}

static void			where_are_you_specifier(t_format *format, t_conversion *conversion)
{
	if (parse_valide_specifier(format, conversion))
	{
		parse_upper_specifier(format, conversion);
		format->cur++;
	}
	else if (parse_invalide_specifier(format))
	{
		conversion->specifier = INVALIDE_SPECIFIER;
		ft_putendl("je suis la");
	}
	else
	{
		conversion->specifier = NO_SPECIFIER;
		ft_putchar(format->string[format->cur++]);
		format->ret++;
	}
}

void			check_format(t_format *format, va_list arguments)
{
	t_conversion conversion;

	ft_bzero(&conversion, sizeof(conversion));
	check_flags(format, &conversion);
	check_width(format, &conversion);
	check_precision(format, &conversion);
	parse_length_modifier(format, &conversion);
	where_are_you_specifier(format, &conversion);
	print_type(format, &conversion, arguments);
}

int		ft_printf(const char *fmt, ...)
{
	t_format		format;
	va_list			arguments;

	va_start(arguments, fmt);
	ft_bzero(&format, sizeof(format));
	format.string = (char*)fmt;
	while (format.string[format.cur])
	{
		if (format.string[format.cur] == '%')
		{
			format.cur++;
			check_format(&format, arguments);
		}
		else
		{
			ft_putchar(format.string[format.cur++]);
			format.ret++;
		}
	}
	va_end(arguments);
	return (format.ret);
}

/*int	main()
{
	ft_printf("%x\n", 0);
	printf("%x\n", 0);
}*/
