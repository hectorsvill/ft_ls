/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getasset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:55:23 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:33:23 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_lcc(const char **fmt, t_fmt *f, size_t flags_len,
		va_list args, int *fin_size)
{
	if (**fmt == 'l')
	{
		(*fmt)++;
		f->con_spec = 'C';
	}
	else
		f->con_spec = **fmt;
	if (f->con_spec == 'C')
		flag_wc(args, ft_strndup((*fmt) - flags_len, flags_len), fin_size, f);
	else
		flag_c(args, ft_strndup((*fmt) - flags_len, flags_len), fin_size, f);
}

static void	get_asset_numbers(const char **fmt, va_list args, int *fin_size,
		t_fmt *f, int flags_len)
{
	if (**fmt == 'i' || **fmt == 'd' || **fmt == 'p' || **fmt == 'u' ||
		**fmt == 'o' || **fmt == 'x' || **fmt == 'X')
	{
		f->con_spec = (**fmt == 'd') ? 'i' : **fmt;
		flag_i(args, ft_strndup((*fmt) - flags_len, flags_len), fin_size, f);
	}
	else if (**fmt == 'D' || **fmt == 'O' || **fmt == 'U')
	{
		f->length_mod = "l";
		if (**fmt == 'D')
			f->con_spec = 'i';
		else if (**fmt == 'O')
			f->con_spec = 'o';
		else if (**fmt == 'U')
			f->con_spec = 'u';
		flag_i(args, ft_strndup((*fmt) - flags_len, flags_len), fin_size, f);
	}
}

static void	get_asset_chars(const char **fmt, va_list args, int *fin_size,
	t_fmt *f, int flags_len)
{
	if (**fmt == '%')
	{
		flag_mod( ft_strndup((*fmt) - flags_len, flags_len + 1), fin_size, f);
	}
	else if (((**fmt == 'l' && *((*fmt) + 1) == 'c') || **fmt == 'C') ||
		**fmt == 'c')
	{
		set_lcc(fmt, f, flags_len, args, fin_size);
	}
	else if (((**fmt == 'l' && *((*fmt) + 1) == 's') || **fmt == 'S') ||
		**fmt == 's')
	{
		if (**fmt == 'l')
		{
			(*fmt)++;
			f->con_spec = 'S';
		}
		else
			f->con_spec = **fmt;
		flag_s(args, ft_strndup((*fmt) - flags_len, flags_len), fin_size, f);
	}
}

static char	ifchar(const char **fmt)
{
	if (**fmt == '%' || (((**fmt == 'l' && *((*fmt) + 1) == 'c') ||
		**fmt == 'C') || **fmt == 'c') || (((**fmt == 'l'
		&& *((*fmt) + 1) == 's') || **fmt == 'S') || **fmt == 's'))
		return (1);
	else
		return (0);
}

void		get_asset(const char **fmt, va_list args, int *fin_size)
{
	size_t	flags_len;
 	t_fmt	*f;

	f = f_set();
	flags_len = 0;
	while (**fmt)
	{
		if (ifchar(fmt))
		{
			get_asset_chars(fmt, args, fin_size, f, flags_len);
			break ;
		}
		else if (ifnumber(**fmt))
		{
			get_asset_numbers(fmt, args, fin_size, f, flags_len);
			break ;
		}
		else if (*((*fmt) + 1) == 0)
			break ;
		(*fmt)++;
		flags_len++;
	}
}
