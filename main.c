#include "ft_ls.h"

/*
	1.store directory names in link list.
	2.sort list of names with merge sort.
	3.print list of names

*/

void print_list(t_ftls *list)
{
	int sp;
	sp = 0;
	while (list)
	{
		if (ft_strncmp(list->names, ".", 1))
			ft_putendl(list->names );
		//ft_putstr("    ");
		list = list->next;
	}

}
void ftls_lstadd(t_ftls **alst, t_ftls *t_new)
{
	t_new->next = *alst;
	*alst = t_new;
}

t_ftls *ftls_lstnew(char *name)
{
	t_ftls *link;

	link = (t_ftls*)malloc(sizeof(t_ftls));
	link->names = ft_strdup(name);
	return (link);
}

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
			//tmp = ft_lstnew(ft_strdup(sd->d_name), ft_strlen(sd->d_name));
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
	opendir_getnames(&name_list, av[1]);
	return (0);
}
