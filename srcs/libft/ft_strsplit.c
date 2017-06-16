/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 00:24:35 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/17 06:34:47 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	lengthnoc(char *s, char c)
{
	size_t		len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len++;
			while (*s && *s != c)
				s++;
		}
	}
	return (len);
}

static size_t	loop_is_isnot(char *s, char c)
{
	size_t		i;
	size_t		cc;

	i = 0;
	cc = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		cc++;
	}
	return (cc);
}

static	char	**strsplit_loop(char **str, char *s, char c, size_t slen)
{
	size_t		t;
	size_t		i;
	size_t		j;

	i = 0;
	t = 0;
	while (t < slen)
	{
		if (!(str[t] =
					(char*)malloc(sizeof(char) * loop_is_isnot(&s[i], c) + 1)))
			return (0);
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			str[t][j++] = s[i++];
		str[t][j] = 0;
		t++;
	}
	str[t] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		slen;
	char		**str;

	if (!s)
		return (0);
	slen = lengthnoc((char *)s, c);
	str = (char **)malloc(sizeof(char*) * slen + 1);
	if (!str)
		return (0);
	return (strsplit_loop(str, (char *)s, c, slen));
}
