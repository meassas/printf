/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width_with_space_or_zero.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:07:42 by meassas           #+#    #+#             */
/*   Updated: 2017/08/05 17:01:14 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_width_spaces(char c, size_t length, t_format *format, t_conversion *conversion)
{
	size_t	i;

	if (c != ' ')
		return ;
	i = 0;
	if (conversion->negative)
		length += 1;
	while (i + length < conversion->width)
	{
		ft_putchar(c);
		i++;
		format->ret++;
	}
}

void		add_width_zeros(char c, size_t length, t_format *format, t_conversion *conversion)
{
	size_t	i;

	if (c != '0')
		return ;
	i = 0;
	if (conversion->negative)
		length += 1;
	while (i + length < conversion->width)
	{
		ft_putchar(c);
		i++;
		format->ret++;
	}
}

void		precision_zeros(t_format *format, t_conversion *conversion, char *string)
{
	int c;

	c = ft_strlen(string);
	while (c < conversion->get_precision)
	{
		ft_putchar('0');
		c++;
		format->ret++;
	}
}
