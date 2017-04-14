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
 		opendir_getnames(&entries.dirs->files, ".");
		merge_sort(&entries.dirs->files);
		print_list(entries.dirs->files);
		return (0);
	}
	//get arg
	if (av[1][0] == '-')
	{
		/**
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

			opendir_getnames(&entries.file_list, av[1]);
			merge_sort(&entries.file_list);
			print_list(entries.file_list);

	}

	return (0);
}
