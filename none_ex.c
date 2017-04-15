

#include "ft_ls.h"



char isvalidfile(t_files *dirs, char *name)
{
	char valid;

	valid = 0;
	while(dirs)
	{
		if (!strcmp(dirs->file, name))
			return (1);
		dirs = dirs->next;
	}
	return (valid);
}

void addto_file_list(char **av,
	t_files **dirs, t_files **file_list, t_files **none_ex)
{
	*file_list = NULL;
	*none_ex = NULL;
	while (*av)
	{
		/**
		**	check if *av is a valid flags
		**	if valid flag then add too file_list
		**	else add to none_ex;
		**/

		if (isvalidfile(*dirs, *av))
			lstadd_files(file_list, *av);
		else
			lstadd_files(none_ex, *av);

		av++;
	}
}
