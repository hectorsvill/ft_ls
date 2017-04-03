/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:36:07 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/17 06:38:38 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s_cat;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len < size)
	{
		s_cat = dst + dst_len;
		ft_bzero(s_cat, size - dst_len);
		ft_memcpy(s_cat, src, size - dst_len - 1);
		return (dst_len + src_len);
	}
	return (size + src_len);
}
