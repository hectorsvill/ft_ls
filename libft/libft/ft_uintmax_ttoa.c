/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_ttoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:48:58 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 18:29:41 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(uintmax_t n)
{
	intmax_t	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_uintmax_ttoa(uintmax_t n)
{
	size_t	len;
	char	*str;

	len = get_len(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (n == 0)
		str[--len] = '0';
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
