#include "ft_printf.h"

void		check_width(t_format *format, t_conversion *conversion)
{
	unsigned int ret;
	int digit;

	digit = format->string[format->cur];
	ret = 0;
	if (ft_isdigit(digit))
	{
		ret = ft_atoi(&format->string[format->cur]);
		//printf("ret = %d\n", ret);
		conversion->width = ret;
		//printf("conversion->width = %d\n", conversion->width);
		//printf("digit[48-57] = %d\n", digit);
	}
	if (conversion->width)
		format->cur += ft_strlen(ft_itoa(conversion->width));
	//else
	//	format->cur++;
	//printf("strlen f->s = %d\n", (int)ft_strlen(&format->string[format->cur]));
	//printf("format->cur = %c\n", format->string[format->cur]);
	//printf("ret = %d\n", ret);
	//printf("digit = %d\n", digit);
	//printf("conversion->width = %d\n", conversion->width);
}

/*int		main()
{
	t_format		format;
	t_conversion	conversion;

	format.string = "fqeff100.5afLN";
	format.cur = 0;
	while (format.string[format.cur])
	{
		if (conversion.width)
			break ;
		printf("format->cur = %c\n", format.string[format.cur]);
		check_width(&format, &conversion);
	}
	return (0);
}*/
