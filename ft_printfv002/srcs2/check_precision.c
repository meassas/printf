/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 12:09:59 by meassas           #+#    #+#             */
/*   Updated: 2017/09/10 20:03:24 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		if (i == 0)
			conversion->precision = 0;
	}
}
