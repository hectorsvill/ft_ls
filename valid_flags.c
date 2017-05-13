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
		else if (*str_flags == 'g')
			flags |= GROUP_NAME;
		str_flags++;
	}
	return (flags);
}

static char checkflag(char cf)
{
	char *flags;

	flags = ft_strndup("1lRartg", 7);
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

t_flags getallflags(char **av)
{
	t_flags flags;
	char flagcheck;


	flagcheck = 0;
	flags = 0;
	if (!ft_strcmp(*av, "-"))
	{
		ft_putendl("ls: -: No such file or directory");
		exit(1);
	}
	flagcheck = checkflags(*av);
	if (flagcheck == 1)
		flags = setfield(*av);
	else
	{
		if (flagcheck != '1')
		{
			ft_printf("/bin/ls: illegal option -- %c\n", flagcheck);
			ft_putendl("usage: ls [-lrartg] [file ...]");
			exit(1);
		}
	}
	return (flags);
}
