/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 09:54:07 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:19:07 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_mod(char *fmt, int *fin_size, t_fmt *f)
{
	setforprint(fmt, f);
	get_prec_min(f, fmt);
	f->precision = 0;
	f->arg_len = 1;
	if (f->neg)
		ft_putchar('%');
	if (f->min_width)
		ft_putwhtsp(f);
	if (!f->neg)
		ft_putchar('%');
	*fin_size += f->min_width ? f->min_width : 1;
}

void	get_prec_min(t_fmt *f, char *fmt)
{
	while (*fmt)
	{
		if (ft_isdigit(*fmt) && *fmt != '0')
		{
			if (*(fmt - 1) == '.')
				f->precision = ft_digitInStr(&fmt);
			else
				f->min_width = ft_digitInStr(&fmt);
		}
		fmt++;
	}
}

void	print_wc(t_fmt *f, char p)
{
	char mb[4];

	f->arg_len  = ft_wctomb(mb, f->arg.wit);
	if (p)
		write(1, mb, f->arg_len);
}

void	flag_wc(va_list args, char *fmt, int *fin_size, t_fmt *f)
{
	setforprint(fmt, f);
	get_prec_min(f, fmt);
	f->precision = 0;
	get_conversion(f, args);
	print_wc(f, 0);
	ft_print(f);
	*fin_size += f->min_width ? f->min_width : f->arg_len;
	free((void*)f);
}

void	flag_c(va_list args, char *fmt, int *fin_size, t_fmt *f)
{
	setforprint(fmt, f);
	get_prec_min(f, fmt);
	get_conversion(f, args);
	f->arg_len = 1;
	ft_print(f);
	*fin_size += f->min_width ? f->min_width : f->arg_len;
	free((void*)f);
}
