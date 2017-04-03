/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:46:59 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/16 17:53:45 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_c;

	s_c = (char *)s + ft_strlen(s);
	while (s_c >= s)
	{
		if (*s_c == c)
			return (s_c);
		--s_c;
	}
	return (0);
}
