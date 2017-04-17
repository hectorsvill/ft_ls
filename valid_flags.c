#include "ft_ls.h"




/**
**	TODO: Go through flag str and set bitfield
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
		str_flags++;
	}
	return (flags);
}

/**
**	TODO: Check for valid flags.
**		  retunr 1 if all valid flags else 0.
**		  valid flags: l R a r t
**/

char checkflag(char cf)
{
	char *flags;

	flags = ft_strndup("lRart", 5);
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
