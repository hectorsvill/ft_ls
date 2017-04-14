#include "ft_ls.h"

/*
	1.store directory names in link list.
	2.sort list of names with merge sort.
	3.print list of names

*/


void opendir_getnames(t_entries **name_list, char *name)
{
    /**
    **  This fx writes a list of the directory name
    */
    DIR             	*dir;
    struct dirent   	*sd;
	t_entries			*tmp;

	tmp = NULL;
    dir = opendir(name);
    if (!dir)
		ft_printf("ls: %s: No such file or directory\n", name);
	else
	{

		while ((sd = readdir(dir)) != NULL)
		{
			tmp = ftls_lstnew_entries(sd->d_name);
			ftls_lstadd(name_list, tmp);
		}
		closedir(dir);
	}
}

int main(int ac, char **av)
{
	t_entries *entries;

	entries = NULL;
	if (ac == 1)
	{
 		opendir_getnames(&entries, ".");
		//merge_sort(&entries);
		print_list(entries->files);
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
