

#include "ft_ls.h"



void get_stat(t_files *file_list)
{
	struct stat sb;

	while (file_list)
	{
		if ((stat(file_list->file, &sb)) == -1)
		{
			ft_printf("Not valid file: %s\n", file_list->file);
			//perror("stat == -1");
			//exit(EXIT_FAILURE);
		}

		ft_printf("Is valid file: %s\n", file_list->file);

		file_list = file_list->next;
	}
}

void addto_file_list(char **av, t_files **file_list)
{
	/**
	**	add all av values to file list
	**	to start checking files with stat6
	**/
	*file_list = NULL;
	while (*av)
	{
		lstadd_files(file_list, *av);
		av++;
	}
	get_stat(*file_list);
	exit(1);
}
