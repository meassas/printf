/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:52:23 by meassas           #+#    #+#             */
/*   Updated: 2017/05/22 18:36:02 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../lib_printf/libft.h"
#include <locale.h>
#include "ft_printf.h"

/*int		main()
{
	char *s;
	char c;
	double d;
	int i;

	i = -42;
	d = 19;
	c = 'z';
	s = "suce";
	printf("test 0 = %10d\n", i);
	printf("test 1 = %0d\n", i);
	printf("test 2 = %-10d\n", i);
	printf("test 3 = %010d\n", i);
	printf("test 4 = %4d\n", i);
	printf("test 4 = %hd\n", i);
	printf("test 4 = %4d\n", i);
	printf("test 0bis %       %(s) = %5%\n");
	printf("test 0bis %       %(s) = %5%\n");
	printf("test 0bis %       %(s) = %5%\n");
	printf("test 0bis %       %(s) = %5%\n");
	return (0);
}*/
//	printf("\033[0;32m----------------TEST---------------------\033[0m\n");
//	printf("%s----------------TEST---------------------%s\n", RED, END);
/*	printf("test 0 10(s) = %10s\n", s);
	printf("test 0bis %       %(s) = %5%\n");
	printf("test 1 10.3(s) = %10.s\n", s);
	printf("test 2 10.5(s) = %10.5s\n", s);
	printf("test 3 .2(s) = %.2s\n", s);
	printf("test 4 0(d) = %0d\n", c);
	printf("test 4bis 0.3(d) = %0.3d\n", c);
	printf("test 5 11.10(d) = %11.10d\n", c);
	printf("test 6 0*(f) = %0*o\n", 5, i);
	printf("test 7 #(x) = %#x\n", c);
	printf("test 8 #(o) = %#o\n", c);
	printf("test 9 #(X) = %#X\n", c);
	printf("test 10 +(d) = %+d\n",c);
	printf("test 11 -(d) = %-d\n",c);
	printf("test 12  (d) = % d\n",c);
	printf("test 13 0(d) = %0d\n",c);
	printf("test 14 (o) = %o\n", c);
	printf("test 14bis #(o) = %#o\n", c);
	printf("test 15 #1(o) = %#1o\n", c);
	printf("test 16 #1.5(o) = %#2.1o\n", c);
	printf("test 17 (o) = %o\n", i);
	printf("test 17bis (o) = %o\n", c);
	printf("test 17ter (o) = %o\n", i);
	printf("test 17ter (o) = %x\n", i);
	return (0);
}*/

/*int		main_printf(int ac, char **av)
{
	printf("petit s = %s\n", av[1]);
	printf("petit d = %d\n", *av[1]);
	printf("petit i = %i\n", *av[1]);
	printf("petit x = %x\n", *av[1]);
	printf("petit p = %p\n", av[1]);
	printf("petit o = %o\n", *av[1]);
	printf("petit u = %u\n", *av[1]);
	printf("petit c = %c\n", *av[1]);
	printf("grand D = %D\n", *av[1]);
	printf("grand O = %O\n", *av[1]);
	printf("grand X = %X\n", *av[1]);
	printf("grand U = %U\n", *av[1]);
	printf("pourcent fois deux =  %%s\n");
	printf("petit i et flags ' '= % i\n", *av[1]);
}*/

/*int		ft_printf(char *fmt, ...)
{
	va_list ap;
	int d;
	char *s;
	char c;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if ((*fmt + 1) == '%')
			{
				ft_putchar('%');
				fmt++;
				return (0);
			}
			fmt++;
		}
		if (*fmt == 'd' || *fmt == 'i')
		{
			d = va_arg(ap, int);
			ft_putnbr(d);
		}
		if (*fmt == 's')
		{
			s = va_arg(ap, char *);
			ft_putstr(s);
		}
		if (*fmt == 'c')
		{
			c = va_arg(ap, int);
			ft_putchar(c);
		}
		else
			ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (0);
}

int		main(int ac, char **av)
{
	int d;
	char c;
	char *s;

	d = 1;
	c = 49;
	s = "salut la miff";
	ft_putstr("d = ");
	ft_printf("%d", d);
	ft_putchar('\n');
	ft_putstr("s = ");
	ft_printf("%s", s);
	ft_putchar('\n');
	ft_putstr("c = ");
	ft_printf("%c", c);
	ft_putchar('\n');
	ft_putendl("-----mon printf-----");
	ft_printf("%% %c\n %#s\n %d\n", c, s, d);
	ft_putendl("-----vrai printf-----");
	printf("%% |%c\n %s\n %d\n %x\n", c, s, d, d);
	ft_putchar('\n');
	return (0);
}*/
