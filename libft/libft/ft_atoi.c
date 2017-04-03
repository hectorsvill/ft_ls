/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:42:00 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/07 19:11:08 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	total;
	size_t	n;

	n = 1;
	total = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		n *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		total *= 10;
		total += (*str - '0');
		str++;
	}
	return (total * n);
}
