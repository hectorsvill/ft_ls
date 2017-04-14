#include "ft_ls.h"

/*
	1.store directory names in link list.
	2.sort list of names with merge sort.
	3.print list of names

*/


void opendir_getnames(t_ftls **name_list, char *name)
{
    /**
    **  This fx writes a list of the directory name
    */
    DIR             *dir;
    struct dirent   *sd;
	t_ftls			*tmp;

	tmp = NULL;
    dir = opendir(name);
    if (!dir)
		ft_printf("ls: %s: No such file or directory\n", name);
	else
	{
		while ((sd = readdir(dir)) != NULL)
		{
			tmp = ftls_lstnew(sd->d_name);
			ftls_lstadd(name_list, tmp);
		}
		closedir(dir);
	}
}

int main(int ac, char **av)
{
	t_ftls *name_list;

	name_list = NULL;
	if (ac == 1)
	{
 		opendir_getnames(&name_list, ".");
		merge_sort(&name_list);
		print_list(name_list);
		return (0);
	}
	//get arg
	if (av[1][0] == '-')
	{
	}
	else
	{

			while (*av)
			{
				ft_putendl(*av);
				av++;
			}

	}
	//opendir_getnames(&name_list, av[1]);
	//merge_sort(&name_list);
	//print_list(name_list);

	return (0);
}
