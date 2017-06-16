/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 01:49:39 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/18 00:14:47 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	slen;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		str[i] = f(*s);
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
