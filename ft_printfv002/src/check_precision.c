#include "ft_printf.h"

void		check_precision(t_format *format, t_conversion *conversion)
{
	int i;

	i = 0;
	if (format->string[format->cur] == '.')
	{
		conversion->precision = 1;
		if ((i = (ft_atoi(&format->string[++format->cur]))))
		format->cur += ft_strlen(ft_itoa(i));
		conversion->get_precision = i;
	}
}
