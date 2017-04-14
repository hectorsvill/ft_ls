

#include "ft_ls.h"


void addto_file_list(char **av, t_files **files)
{
	char ex;

	ex = 0;
	*files = NULL;
	while (*av)
	{
		lstadd_files(files, *av);
		//ft_putendl(*av);
		av++;
	}

}
