/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:47:47 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/05 23:39:56 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char uc;
	unsigned char *us;

	us = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*us == uc)
			return (us);
		us++;
	}
	return (NULL);
}
