/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width_with_space_or_zero.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:07:42 by meassas           #+#    #+#             */
/*   Updated: 2017/09/09 21:43:21 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		add_width_spaces(char c, size_t length, t_format *format, t_conversion *conversion)
{
	size_t	i;

	if (c != ' ')
		return ;
	i = 0;
	if (conversion->negative)
		length += 1;
	if (conversion->specifier == POINTER)
		length += 4;
	if (conversion->specifier == HEX && conversion->flags.hashtag)
		length += 2;
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
	if (conversion->specifier == HEX && conversion->flags.hashtag)
		length += 2;
	//if (conversion->specifier == POINTER)
	//	length += 4;
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
	if (conversion->width)
		conversion->get_precision = 0;
	while (c < conversion->get_precision)
	{
		ft_putchar('0');
		c++;
		format->ret++;
	}
}
