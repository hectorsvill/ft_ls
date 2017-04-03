/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:45:59 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:16:50 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ls_prec(va_list args)
{
	wchar_t *wstr;

	wstr = va_arg(args, wchar_t*);
	return (wstr);
}

void		print_ls(wchar_t *wct, int len)
{
	int		size;
	char	mb[4];

	size = 0;
	if (wct == NULL)
		ft_putstr("(null)");
	else
	{
		while(*wct && len > 0)
		{
			size = ft_wctomb(mb, *wct);
			if (size > len)
				break;
			write(1, mb, size);
			len -= size;
			wct++;
		}
	}
}

int			ft_wcstrlen(wchar_t *wct)
{
	int		size;
	char	mb[4];

	size = 0;
	while (*wct)
	{
		size += ft_wctomb(mb, *wct);
		wct++;
	}
	return (size);
}

int			ft_wcstrlenpr(wchar_t *wct, int len)
{
	int		size;
	char	mb[4];

	size = 0;
	while (*wct && len > 0)
	{

		size += ft_wctomb(mb, *wct);
		if (size < len)
			break;
		wct++;
		len -= size;
	}
	return (size);
}

size_t		prec_set_zerostr(char *fmt)
{
	size_t	d;

	d = 0;
	while (*fmt)
	{
		if (*fmt == '.' && (!ft_isdigit(*(fmt + 1)) || *(fmt + 1) == '0'))
			d = 1;
		fmt++;
	}
	return (d);
}
