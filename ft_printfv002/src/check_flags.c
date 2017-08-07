#include "ft_printf.h"

/*static void	init_flags(t_conversion *conversion)
{
	conversion->flags.left_justifier = 0;
	conversion->flags.sign_justifier = 0;
	conversion->flags.pad_with_zeros = 0;
	conversion->flags.hashtag = 0;
	conversion->flags.pad_with_blank = 0;
}*/

static int	parse_flags_plus(t_format *format, t_conversion *conversion)
{
//	init_flags(conversion);
	if (format->string[format->cur] == '-')
	{
		conversion->flags.left_justifier = 1;
		if (conversion->flags.pad_with_zeros)
			conversion->flags.pad_with_zeros = 0;
		return (1);
	}
	else if (format->string[format->cur] == '0')
	{
		if (!conversion->flags.left_justifier)
			conversion->flags.pad_with_zeros = 1;
		return (1);
	}
	return (0);
}

static int	parse_flags(t_format *format, t_conversion *conversion)
{
	if (format->string[format->cur] == '#')
	{
		conversion->flags.hashtag = 1;
		return (1);
	}
	else if (format->string[format->cur] == '+')
	{
		conversion->flags.sign_justifier = 1;
		if (conversion->flags.pad_with_blank)
			conversion->flags.pad_with_blank = 0;
		return (1);
	}
	else if (format->string[format->cur] == ' ')
	{
		if (!conversion->flags.sign_justifier)
			conversion->flags.pad_with_blank = 1;
		return (1);
	}
	return (parse_flags_plus(format, conversion));
}

void			check_flags(t_format *format, t_conversion *conversion)
{
	while (parse_flags(format, conversion))
	{
	//	printf("f.s[f.c] = %c\n", format->string[format->cur]);
	//	printf("c.f.0 = %d\n", conversion->flags.pad_with_zeros);
	//	printf("c.f.- = %d\n", conversion->flags.left_justifier);
	//	printf("c.f.+ = %d\n", conversion->flags.sign_justifier);
	//	printf("c.f.space = %d\n", conversion->flags.pad_with_blank);
		format->cur++;
	}
}

/*int		main()
{
	t_format		*format;
	t_conversion	conversion;

	//format->string = "0-";
	//format->string = "0-0";
	format->string = " +";
	//format->string = " + ";
	//format->string = "#";
	//format->string = "0+";
	format->cur = 0;
	while (format->string[format->cur])
	{
		while (parse_flags(format, &conversion))
		{
			printf("ret parse_flag = %d\n", parse_flags(format, &conversion));
			printf("f.s[f.c] = %c\n", format->string[format->cur]);
			printf("c.f.0 = %d\n", conversion.flags.pad_with_zeros);
			printf("c.f.- = %d\n", conversion.flags.left_justifier);
			printf("c.f.+ = %d\n", conversion.flags.sign_justifier);
			printf("c.f.space = %d\n", conversion.flags.pad_with_blank);
			printf("c.f.# = %d\n", conversion.flags.hashtag);
			format->cur++;
		}
		format->cur++;
	}
	return (0);
}*/
