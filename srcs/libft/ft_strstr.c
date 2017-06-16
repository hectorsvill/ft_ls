/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 03:15:26 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/16 15:41:06 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t len;

	len = ft_strlen(little);
	if (little[0] == 0)
		return ((char *)big);
	while (*big)
	{
		if (ft_strnequ(big, little, len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
