

#include "ft_ls.h"

char isvalidfile(t_files *dirs, char *name)
{
	char valid;
	/**
	**	Traverse list to check if name is a valid
	**	file in directory
	**/
	valid = 0;
	while(dirs)
	{
		if (!strcmp(dirs->file, name))
			return (1);
		dirs = dirs->next;
	}
	return (valid);
}

void addto_file_list(char **av, t_files **file_list)
{
	/**
	**	add all av values to file list
	**	to start checking for valid output
	**/
	*file_list = NULL;
	while (*av)
	{
		lstadd_files(file_list, *av);
		av++;
	}
}
