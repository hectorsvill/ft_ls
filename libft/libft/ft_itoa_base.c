/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:25:14 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 18:25:24 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_base_len(unsigned long nbr, int base)
{
	int		len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(uintmax_t nbr, int base)
{
	char	*str;
	char	*tab;
	int		len;
	int		i;

	if (nbr == 0)
		return (ft_strdup("0"));
	tab = ft_strdup("0123456789abcdef");
	len = nbr_base_len(nbr, base);
	str = ft_strnew(len);
	i = 1;
	while (nbr > 0)
	{
		str[len - i] = tab[nbr % base];
		nbr /= base;
		i++;
	}
	free((void*)tab);
	return (str);
}
