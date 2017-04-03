/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagi_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 22:42:34 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:24:51 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_lenprint_iu(t_fmt *f)
{
	char	*str;

	if (f->con_spec == 'i')
			str = ft_intmax_ttoa(f->arg.i);
	else
	{
		if (f->arg.u == 0)
			str = "0";
		else
			str = ft_uintmax_ttoa(f->arg.u);
	}
	f->arg_len = (int)ft_strlen(str);
	return (str);
}

static void	check_noneg(int min_width, t_fmt *f)
{
	if ((f->min_width > f->precision && (f->precision != f->arg_len)) ||
		(f->precision == f->arg_len &&
		f->min_width > f->precision && f->arg.i > 0))
	{
		min_width = (f->precision < f->arg_len) ?
			f->min_width - f->arg_len : f->min_width - f->precision;
		min_width -= ((f->pos || ((f->precision > f->arg_len) && f->arg.i < 0))
			|| (f->pos && f->arg.i < 0)) ? 1 : 0;
		if (f->hash && (f->con_spec != 'i' && f->con_spec != 'u'))
			f->min_width += (f->con_spec == 'x' || f->con_spec == 'X' ||
			f->con_spec == 'p') ? 2 : 1;
		f->width_prec_len += min_width;
		while (min_width-- > 0)
			ft_putchar(' ');
		if (f->pos && f->arg.i >= 0)
			ft_putchar('+');
	}
	if (f->con_spec == 'o' && !f->min_width && f->precision && f->hash)
		f->precision -= 1;
	f->zero = 1;
	f->min_width = (f->pos || f->arg.i < 0) ? 1 : 0;
	if (f->hash)
		f->min_width += (f->con_spec == 'x' || f->con_spec == 'X' ||
		f->con_spec == 'p') ? 2 : 1;
	f->min_width += f->precision;
}

static void	check_neg(int min_width, t_fmt *f)
{
	min_width = (f->precision <= f->arg_len) ?
	0 : f->precision - f->arg_len;
	f->min_width -= f->pos ? min_width + 1 : min_width;
	f->width_prec_len += 1;
	if ((f->pos || f->arg.i < 0) && f->arg.i < 0)
		ft_putchar('-');
	while (min_width-- > 0)
		ft_putchar('0');
	f->pos = 0;

}

static void	elseneg(int min_width, t_fmt *f)
{
	if (f->pos && f->arg.i >= 0)
	{
		f->width_prec_len += 1;
		ft_putchar('+');
	}
	if (f->min_width > f->precision)
		check_neg(min_width, f);
	else
	{
		f->min_width = f->precision;
		f->zero = 1;
		f->pos = 0;
		f->neg = 0;
	}
}

void		print_widthprec(t_fmt *f)
{
	int		min_width;

	min_width = 0;
	if (f->precision)
	{
		f->con_spec == 'i' || f->con_spec == 'u' ? get_lenprint_iu(f) :
		get_lenprint_oxXp(f, 0);
		if (!f->neg)
			check_noneg(min_width, f);
		else
			elseneg(min_width, f);
	}
}
