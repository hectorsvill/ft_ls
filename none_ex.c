

#include "ft_ls.h"


/**
**	Traverse throught file_list and use stat
**	if file is not valid insert into none_ex
**	else ...
**	if file is dir create new link for dirs
**	and get and sort those dirs
**/
void get_stat(t_files *file_list, t_dirs **dirs, t_files **none_ex)
{
	struct stat sb;

	*none_ex = NULL;
	*dirs = NULL;
	while (file_list)
	{

		if ((stat(file_list->file, &sb)) == -1)
		{
			/**
			**	unlink unexisting file from file_list and
			**	add name to none_ex
			**/
			lstadd_files(none_ex, file_list->file);
			//maybe remove from list none_ex file form file_list;
		}
		else
		{

			/**
			**	add list to file_list
			**/
			if(S_ISREG(sb.st_mode))
			{
				//do nothing for now
				//file would be in cureent directory
				//ft_printf("ISREG!:%i\n", S_ISREG(sb.st_mode));
			}

			/**
			**	add list to dirs
			**	and get files from dir
			**/
			if(S_ISDIR(sb.st_mode))
			{
				/**
				**	unlink file from file_list and
				**	add name to dirs
				**/
				lstadd_dirs(dirs, file_list->file);
			}
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
}
