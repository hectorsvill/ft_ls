#include "ft_ls.h"

/*
	1.store directory names in link list.
	2.sort list of names with merge sort.
	3.print list of names

*/


int opendir_getnames(t_files **files, char *dir_name)
{

    DIR             	*dir;
    struct dirent   	*sd;

	*files = NULL;
	if (!(dir = opendir(dir_name)))
		return (0);
	/**
	**	make this function return 0
	**	if dir_name is invalid directory
	**	if invalid d irectory then send to entries.none_ex
	**/

	while ((sd = readdir(dir)) != NULL)
		lstadd_files(files, sd->d_name);
	closedir(dir);
	return (1);
}

int main(int ac, char **av)
{
	t_entries entries;

	entries = entries_init();
	if (ac == 1)
	{
		entries.dirs->dir_name = ".";
 		opendir_getnames(&entries.dirs->files, ".");
		mergesort_files(&entries.dirs->files);
		print_list_noflags(entries.dirs->files);
		return (0);
	}
	//get arg
	if (av[1][0] == '-')
	{
		/**
		**	check for valid flags
		**
		*/

	}
	else if (ac == 2)
	{
		/**
		**	when there are no flags and only one param
		**/
		entries.dirs->dir_name = av[1];
		if (!opendir_getnames(&entries.dirs->files, av[1]))
			ft_printf("ls: %s: No such file or directory\n", av[1]);
		else
		{
			mergesort_files(&entries.dirs->files);
			print_list_noflags(entries.dirs->files);
		}
		return (0);

	}
	else
	{

		/**
		**	only go in if no flags only file names
		**	check if file_list is valid else if not valid insert into none_ex
		**	file names are now in file_list and none existent in none_ex
		**/
		av++;

		addto_list(av, &entries);
		mergesort_dirs(&entries.dirs);
		mergesort_files(&entries.dirs->files);
		mergesort_files(&entries.file_list);
		mergesort_files(&entries.none_ex);


		//print
		print_error_none_ex(entries.none_ex);
		print_list_noflags(entries.file_list);
		print_all_dirs(entries.dirs);
		//ft_putendl("");


/*
		ft_putendl("\nfile_list:");
		print_list_noflags(entries.file_list);
		ft_putendl("");

		ft_putendl("\nnone_ex:");
		print_list_noflags(entries.none_ex);
		ft_putendl("");



		ft_putendl("\ndir->files:");
		print_all_dirs(entries.dirs);
		ft_putendl("");
*/


	}

	return (0);
}
