/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:03:56 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/18 18:03:57 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/**
**	TODO: Go through flag str and set bitfield for entries.flags
**/
t_flags setfield(char *str_flags)
{
	t_flags flags;

	flags = 0;
	str_flags++;
	while (*str_flags)
	{
		if(*str_flags == 'l')
			flags |= LONG_FORMAT;
		else if (*str_flags == 'R')
			flags |= RECURISIVE_LIST;
		else if (*str_flags == 'a')
			flags |= ALL_DIRS;
		else if (*str_flags == 'r')
			flags |= REVERSE_ORDER;
		else if (*str_flags == 't')
			flags |= TIMEMODIFIED_SORT;
		str_flags++;
	}
	return (flags);
}
/**
**	TODO: Check for valid flags.
**		  retunr 1 if all valid flags else 0.
**		  valid flags: l R a r t
**/
static char checkflag(char cf)
{
	char *flags;

	flags = ft_strndup("1lRart", 6);
	while (*flags)
	{
		if (cf == *flags)
			return(1);
		flags++;
	}
	return (0);
}

char checkflags(char *cf)
{
	cf++;
	while (*cf)
	{
		if (!checkflag(*cf))
			return (*cf);
		cf++;
	}
	return(1);
}
