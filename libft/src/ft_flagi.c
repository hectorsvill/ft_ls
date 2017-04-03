/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:55:23 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:33:23 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_id(t_fmt *f)
{
	char *s;

	s = NULL;
	print_widthprec(f);
	if (f->arg.i < 0 && f->con_spec == 'i')
	{
		if (f->neg)
		{
			f->arg.i *= (f->precision) ? -1 : 1;
			print_conversion(f);
			f->zero = 0;
			ft_putwhtsp(f);
		}
		else
			print_idelse(f, s);
	}
	else
		ft_print(f);
}

static void		print_setlenelse(t_fmt *f, int *fin_size)
{
	if (f->con_spec == 'i' && f->sp && !f->neg && f->precision > f->min_width)
	{
		f->width_prec_len += 1;
		ft_putchar(' ');
	}
	print_id(f);
	f->width_prec_len = f->width_prec_len <= -1 ? 0 : f->width_prec_len;
	f->con_spec == 'i' || f->con_spec == 'u' ? get_lenprint_iu(f) :
	get_lenprint_oxXp(f, 0);
	if (f->pos && f->arg.i > 0 && f->min_width < f->arg_len)
		*fin_size += 1;
	else if (f->pos && f->zero && f->min_width && !f->precision &&
		f->min_width <= f->arg_len)
		*fin_size += 1;
	*fin_size += f->arg_len + f->width_prec_len;
}

void			print_setlen(t_fmt *f, int *fin_size)
{
	if ((f->min_width == 0 && f->precision == 0))
	{
		if (f->pos && f->arg.i >= 0)
		{
			*fin_size += 1;
			ft_putchar('+');
		}
		if (f->arg.i > 0 && f->sp && f->con_spec == 'i' && !f->pos)
		{
			ft_putchar(' ');
			*fin_size += 1;
		}
		print_conversion(f);
		*fin_size += (f->con_spec == 'p' && f->arg.u == 0) ?
		 	f->arg_len + 2: f->arg_len;
	}
	else
		print_setlenelse(f, fin_size);
}

static void		ifsetzero(int *fin_size, t_fmt *f)
{
	if (f->hash && (f->con_spec != 'i' || f->con_spec != 'u') && f->arg.u != 0)
	{
		get_lenprint_oxXp(f, 1);
		*fin_size += 1;
	}
	else
	{
		if (f->arg.i == 0 && f->con_spec == 'i' && f->precision)
			print_setlen(f, fin_size);
		else
		{
			ft_putwhtsp(f);
			if (f->con_spec == 'o' && f->hash)
				ft_putchar('0');
			if (f->con_spec == 'p')
			{
				ft_putstr("0x");
				f->width_prec_len += 2;
			}
			*fin_size += (f->hash && f->con_spec == 'o') ? 1 :
				f->width_prec_len;
		}
	}
}

void			flag_i(va_list args, char *fmt, int *fin_size, t_fmt *f)
{
	if (f->con_spec == 'i')
		setforprint(fmt, f);
	else if (f->con_spec == 'u' || f->con_spec == 'o' || f->con_spec == 'x' ||
			f->con_spec == 'X' || f->con_spec == 'p')
		setforprint_uox(fmt, f);
	get_prec_min(f, fmt);
	get_conversion(f, args);
	if (prec_set_zero(fmt) && ((f->arg.i == 0 || f->arg.u == 0)))
		ifsetzero(fin_size, f);
	else
		print_setlen(f, fin_size);
	free((void*)f);
}
