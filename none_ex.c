

#include "ft_ls.h"



void get_stat(t_files *file_list)
{
	struct stat sb;

	while (file_list)
	{
		if ((stat(file_list->file, &sb)) == -1)
		{
			//ft_printf("%u\n",sb.st_mode); returns zero when file is not valid

			/**
			**	add list to none_ex
			**/

			ft_printf("Not valid file: %s\n", file_list->file);
			//perror("stat == -1");
			//exit(EXIT_FAILURE);
		}
		else
		{

			/**
			**	add list to file_list
			**/
			//ft_printf("Is valid file: %s\n", file_list->file);
			ft_printf("%u\n",sb.st_mode);
			if(S_ISREG(sb.st_mode))
				ft_putendl("ISREG!");

			/**
			**	add list to dirs
			**/
			if(S_ISDIR(sb.st_mode))
				ft_putendl("ISDIR!");
			/**
			**	loop dirs and store files 
			**/
		}
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