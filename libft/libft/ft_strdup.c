/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:10:19 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/04 22:53:53 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;

	len = ft_strlen(s1);
	dup = ((char *)malloc(sizeof(char) * len + 1));
	if (dup == NULL)
		return (NULL);
	else
		ft_strcpy(dup, s1);
	return (dup);
}
