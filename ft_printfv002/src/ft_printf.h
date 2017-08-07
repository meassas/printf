#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../lib_printf/libft.h"
# include <stdio.h>
# include <wchar.h>
#include "ft_color.h"

typedef struct		s_format
{
	char			*string;
	size_t			cur;
	size_t			ret;
}					t_format;

typedef struct		s_flags
{
	int			left_justifier;
	int			pad_with_zeros;
	int			sign_justifier;
	int			pad_with_blank;
	int			hashtag;
}					t_flags;

typedef enum		e_length
{
	NO_LENGTH, HH, H, L, LL, J, Z
}					t_length;

typedef enum		e_specifier
{
	NO_SPECIFIER, SIGNED_DECIMAL, UNSIGNED_DECIMAL, OCTAL, HEX, CHAR, STRING,
	POINTER, INVALIDE_SPECIFIER
}					t_specifier;

typedef struct		s_conversion
{
	t_flags			flags;
	unsigned int	width;
	unsigned int	precision;
	int				get_precision;
	int				negative;
	t_length		length;
	t_specifier		specifier;
}					t_conversion;

void				check_flags(t_format *format, t_conversion *conversion);
void				parse_length_modifier(t_format *format, t_conversion *conversion);
void				check_width(t_format *format, t_conversion *conversion);
void				check_precision(t_format *format, t_conversion *conversion);
void				check_specifier(t_format *format, t_conversion *conversion);
void				add_width_zeros(char c, size_t length, t_format *format, t_conversion *conversion);
void				add_width_spaces(char c, size_t length, t_format *format, t_conversion *conversion);
void				ft_putnbr_left(t_format *format, t_conversion *conversion, uintmax_t nb);
void				ft_putnbr_right(t_format *format, t_conversion *conversion, int neg, uintmax_t nb);
void				printf_signed_int(t_format *format, t_conversion *conversion, va_list arguments);
void				printf_unsigned_int(t_format *format, t_conversion *conversion, va_list arguments);
void				check_format(t_format *format, va_list arguments);
void				print_type(t_format *format, t_conversion *conversion, va_list arguments);
int					ft_printf(char const *format, ...);
void				precision_zeros(t_format *format, t_conversion *conversion, char *string);
void				printf_hexa_right(t_format *format, t_conversion *conversion, uintmax_t nb);
void				printf_hexa_left(t_format *format, t_conversion *conversion, uintmax_t nb);
void				handle_hex(t_format *format, t_conversion *conversion, uintmax_t nb);
void				handle_octal(t_format *format, t_conversion *conversion, uintmax_t nb);
void				handle_flags_pointer(t_format *format, t_conversion *convesion, void *nb);
#endif
