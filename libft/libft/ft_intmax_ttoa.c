/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax_ttoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:40:50 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/31 15:40:52 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		get_len(intmax_t n)
{
	intmax_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_intmax_ttoa(intmax_t n)
{
	size_t	len;
	char	*str;

	if ((unsigned long)n == -9223372036854775808UL)
		return ("-9223372036854775808");
	len = get_len(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	if (n == 0)
		str[--len] = '0';
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
