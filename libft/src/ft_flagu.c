/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:42:14 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:40:43 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		p_prec(va_list args)
{
	uintmax_t	nb;

	nb = (uintmax_t)va_arg(args, void*);
	return (nb);
}

intmax_t		i_prec(char *length_mod, va_list args)
{
	intmax_t	nb;

	nb = (intmax_t)va_arg(args, intmax_t);
	if (length_mod == NULL)
		return ((int)nb);
	else if (!ft_strcmp(length_mod, "hh"))
		return ((signed char)nb);
	else if (!ft_strcmp(length_mod, "h"))
		return ((short)nb);
	else if (!ft_strcmp(length_mod, "z"))
		return ((size_t)nb);
	else
		return (nb);
}


uintmax_t		u_prec(char *length_mod, va_list args)
{
	uintmax_t	nb;

	nb = (uintmax_t)va_arg(args, uintmax_t);
	if (length_mod == NULL)
		return ((unsigned)nb);
	else if (!ft_strcmp(length_mod, "hh"))
		return ((unsigned char)nb);
	else if (!ft_strcmp(length_mod, "h"))
		return ((unsigned short)nb);
	else if (!ft_strcmp(length_mod, "z"))
		return ((size_t)nb);
	else
		return (nb);
}

void			setforprint_uox(char *fmt, t_fmt *f)
{
	while (*fmt)
	{
		if (*fmt == '#')
			f->hash = 1;
		if (*fmt == '-')
			f->neg = 1;
		if (*fmt == '0' && !ft_isdigit(*(fmt - 1)) && *(fmt - 1) != '.')
			f->zero = 1;
		if (*fmt == 'h' && f->length_mod == NULL)
			f->length_mod = (*(fmt + 1) == 'h') ? "hh" : "h";
		if (*fmt == 'l' && f->length_mod == NULL)
			f->length_mod = (*(fmt + 1) == 'l') ? "ll" : "l";
		if (*fmt == 'j' && f->length_mod == NULL)
			f->length_mod = "j";
		if (*fmt == 'z' && f->length_mod == NULL)
			f->length_mod = "z";
		fmt++;
	}
}
