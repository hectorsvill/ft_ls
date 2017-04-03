/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitesp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:10:52 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 18:01:44 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ifnumber(char c)
{
	if (c == 'i' || c == 'd' || c == 'p' || c == 'u' ||	c == 'o' ||
		c == 'x' || c == 'X' || c == 'D' || c == 'O' || c == 'U')
		return (1);
	else
		return (0);
}

size_t		prec_set_zero(char *fmt)
{
	size_t	d;

	d = 0;
	while (*fmt)
	{
		if (*fmt == '.')
			d = 1;
		fmt++;
	}
	return (d);
}

size_t		ft_digitInStr(char **fmt)
{
	char	*i_str;
	int		i;

	i = 0;
	while (**fmt)
	{
		if (ft_isdigit(**fmt))
		{
			while (ft_isdigit(**fmt))
			{
				i++;
				(*fmt)++;
			}
			break ;
		}
		(*fmt)++;
	}
	i_str = ft_strndup((*fmt) - i, i);
	i = ft_atoi(i_str);
	free((void*)i_str);
	return (i);
}

static void	whtspnozero(t_fmt *f, int min_width)
{
	if (f->con_spec == 'p')
		min_width -= 2 ;
	if (f->con_spec == 'S' && f->precision &&f->min_width > f->precision)
		min_width = f->min_width - f->precision;
	while (min_width-- > 0)
		ft_putchar(' ');
	if (f->pos && !f->neg && f->arg.i >= 0 && f->con_spec != 's')
		ft_putchar('+');
	if ((f->con_spec == 'o' || f->con_spec == 'x' || f->con_spec == 'X' ||
	f->con_spec == 'p') && f->hash && !f->neg)
		get_lenprint_oxXp(f, 1);
}

void		ft_putwhtsp(t_fmt *f)
{
	int min_width;

	min_width = (f->con_spec == 'S' && f->arg.wct != NULL) ?
		f->min_width - f->precision: f->min_width - f->arg_len;
	f->width_prec_len += (min_width <= 0) ? 0 : min_width;
	if (f->pos && f->arg.i >= 0)
		min_width -= 1;
	if (f->zero)
	{
		if (f->con_spec == 'i' && f->pos && !f->neg && f->arg.i >= 0
				&& !f->precision && f->con_spec != 's')
			ft_putchar('+');
		if (f->con_spec == 'p')
			min_width -= 2;
		while (min_width-- > 0)
			if ((f->con_spec != 'c' || f->con_spec != 's') && f->neg)
				ft_putchar(' ');
			else
				ft_putchar('0');
	}
	else
		whtspnozero(f, min_width);
	f->min_width = (f->min_width < f->arg_len) ? f->arg_len : f->min_width;
}
