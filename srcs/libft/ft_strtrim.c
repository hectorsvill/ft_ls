/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:17:20 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/13 17:38:11 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	size_t	slen;
	size_t	i;
	char	*str;

	slen = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	slen = ft_strlen(&s[i]) - 1;
	while (s[i] && (s[slen + i] == ' ' ||
				s[slen + i] == '\n' || s[slen + i] == '\t'))
		slen--;
	str = ft_strnew(slen + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, s + i, slen + 1);
	return (str);
}
