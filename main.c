#include "ft_ls.h"

/*
	1.store directory names in link list.
	2.sort list of names with merge sort.
	3.print list of names

*/


void opendir_getnames(t_files **files, char *dir_name)
{

    DIR             	*dir;
    struct dirent   	*sd;

	*files = NULL;
	if (!(dir = opendir(dir_name)))
		return ;
	/**
	**	make this function return 0
	**	if dir_name is invalid directory
	**	if invalid d irectory then send to entries.none_ex
	**/

	while ((sd = readdir(dir)) != NULL)
		lstadd_files(files, sd->d_name);
	closedir(dir);
}

int main(int ac, char **av)
{
	t_entries entries;

	entries = entries_init();
	if (ac == 1)
	{
		entries.dirs->dir_name = ".";
 		opendir_getnames(&entries.dirs->files, ".");
		merge_sort(&entries.dirs->files);
		print_list(entries.dirs->files);
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
	else
	{
		/*
		**	if no flags and only files names
		**	store list and sort open dirs one by one
		** check for invalid input
		*/

		entries.dirs->dir_name = ".";
		opendir_getnames(&entries.dirs->files, ".");
		merge_sort(&entries.dirs->files);
		/**
		**	check if file_list is valid else if not valid insert into none_ex
		**	file names are now in file_list and none existent in none_ex
		**/
		av++;
		addto_file_list(av, &entries.file_list);
		merge_sort(&entries.file_list);


		ft_putendl("file_list:");
		print_list(entries.file_list);
		ft_putendl("");


/*
		ft_putendl("dir->files:");
		print_list(entries.dirs->files);
		ft_putendl("");



		ft_putendl("none_ex:");
		print_list(entries.none_ex);
		ft_putendl("");
*/
	}

	return (0);
}
