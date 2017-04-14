#include "ft_ls.h"

/*
	1.store directory names in link list.
	2.sort list of names with merge sort.
	3.print list of names

*/


void opendir_getnames(t_files **files, char *name)
{

    DIR             	*dir;
    struct dirent   	*sd;

	//tdir->dir_name = ft_strdup(name);
	//tmp_file = NULL;
	*files = NULL;
	dir = opendir(name);
//    if (!dir)
	//	{}//ft_printf("ls: %s: No such file or directory\n", name);
	//else
	//{
//	*files = lstnew_files("");
	while ((sd = readdir(dir)) != NULL)
	{
		//tmp_file = lstnew_files(sd->d_name);
		lstadd_files(files, sd->d_name);
	}
	closedir(dir);
	//}
}



t_entries entries_init(void)
{
	t_entries entries;

	//entries = (t_entries*)malloc(sizeof(entries)); //if pointer
	entries.dirs = (t_dirs*)malloc(sizeof(t_dirs));
	entries.dirs->files = (t_files*)malloc(sizeof(t_dirs));
//	entries->file_list = (t_files*)malloc(sizeof(t_dirs));
//	entries->none_ex = (t_files*)malloc(sizeof(t_dirs));
	return (entries);
}

int main(int ac, char **av)
{
	t_entries entries;

	entries = entries_init();
	if (ac == 1)
	{
 		opendir_getnames(&entries.dirs->files, ".");
		//merge_sort(&entries);
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
			while (*av)
			{
				if (av[1])
				ft_putendl(*av);
				av++;
			}

	}
	//opendir_getnames(&entries, av[1]);
	//merge_sort(&entries);
	//print_list(entries);

	return (0);
}
