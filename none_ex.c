

#include "ft_ls.h"


void addto_file_list(char **av, t_files **files)
{
	*files = NULL;
	while (*av)
	{
		/**
		**	check if *av is a valid flags
		**	if valid flag then add too file_list
		**	else add to none_ex;
		**/
		lstadd_files(files, *av);
		av++;
	}
}


char isvalidfile(t_files **dir_files, char *name)
{
	char valid;

	valid = 0;
	while(dir_files)
	{
		if (!strcmp(dir_files->file, name))
			return (1);
		dir_files = dir_files->next;
	}
	return (valid);
}
