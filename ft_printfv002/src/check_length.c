#include "ft_printf.h"

static void		parse_length_modifier_plus(t_format *format, t_conversion *conversion)
{
	if (format->string[format->cur] == 'j')
	{
		conversion->length = J;
		format->cur++;
	}
	else if (format->string[format->cur] == 'z')
	{
		conversion->length = Z;
		format->cur++;
	}
	else
		conversion->length = NO_LENGTH;
	return ;
}

void		parse_length_modifier(t_format *format, t_conversion *conversion)
{
	if (format->string[format->cur] == 'h')
	{
		if (format->string[format->cur + 1] == 'h')
		{
			conversion->length = HH;
			format->cur++;
		}
		else
			conversion->length = H;
		format->cur++;
		return ;
	}
	else if (format->string[format->cur] == 'l')
	{
		if (format->string[format->cur + 1] == 'l')
		{
			conversion->length = LL;
			format->cur++;
		}
		else
			conversion->length = L;
		format->cur++;
		return ;
	}
	parse_length_modifier_plus(format, conversion);
}

/*void		handle_length_for_int(t_format *format, t_conversion *conversion, va_list arg)
{
	intmax_t	ret_arg;

	if (conversion->length == HH)
		ret_arg = va_arg(arg, int);
	else if (conversion->length == H)
		ret_arg = va_arg(arg, int);
	else if (conversion->length == LL)
		ret_arg = va_arg(arg, long long);
	else if (conversion->length == L)
		ret_arg = va_arg(arg, long);
	else if (conversion->length == J)
		ret_arg = va_arg(arg, intmax_t);
	else if (conversion->length == Z)
		ret_arg = va_arg(arg, size_t);
}*/

/*int		main()
{
	va_list arg;


}*/
/*int		main()
{
	t_format format;
	t_conversion conversion;

	format.string = "hhj";
	format.cur = 0;
	conversion.length = 0;
	printf("conversion.length = %d\n", conversion.length);
	printf("f->cur = %c\n", format.string[format.cur]);
	parse_length_modifier(&format, &conversion);
	printf("conversion.length with parse= %d\n", conversion.length);
	printf("f->cur = %c\n", format.string[format.cur]);
	return (0);
}*/
