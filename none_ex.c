

#include "ft_ls.h"


/**
**	Traverse throught file_list and use stat
**	if file is not valid insert into none_ex
**	else ...
**	if file is dir create new link for dirs
**	and get and sort those dirs
**/

/**
** 	use stat to collect file information imidiately
** send files to proper list!
**/
void addto_list(char **av, t_entries *ent)
{
	struct stat sb;

	ent->dirs = NULL;
	ent->file_list = NULL;
	ent->none_ex = NULL;
	while (*av)
	{
		if ((stat(*av, &sb)) == -1)
		{
			lstadd_files(&ent->none_ex, *av);
			//ft_putendl(*av);
		}
		if (S_ISREG(sb.st_mode))
		{
			lstadd_files(&ent->file_list, *av);
		}
		else if(S_ISDIR(sb.st_mode))
		{
			lstadd_dirs(&ent->dirs, *av);
		}
		av++;
	}
}


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
		}
		else
		{
			if(S_ISREG(sb.st_mode))
			{
				//do nothing for now
				//file would be in cureent directory
				//ft_printf("ISREG!:%i\n", S_ISREG(sb.st_mode));
			}
			if(S_ISDIR(sb.st_mode))
			{
				/**
				**	?unlink file from file_list and?
				**	add name to dirs and files to dirs->files
				**/
				lstadd_dirs(dirs, file_list->file);
			}
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
