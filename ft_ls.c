#include "ft_ls.h"

/*
	1.store directory names in link list.
	2.sort list of names with qsort.
	3.print list of names

*/

void print_list(t_list *list)
{
	int sp;
	sp = 0;
	while (list)
	{

		ft_putendl(list->content);
		//ft_putstr("    ");
		list = list->next;
	}

}

void opendir_getnames(t_list **name_list, char *name)
{
    /**
    **  This fx writes a list of the directory name
    */
    DIR             *dir;
    struct dirent   *sd;
	t_list			*tmp;

    dir = opendir(name);
    if (!dir)
		ft_printf("ls: cannot access %s: No such file or directory\n", name);

	//*name_list = ft_lstnew("", 0);
	while ((sd = readdir(dir)) != NULL)
	{
		tmp = ft_lstnew(ft_strdup(sd->d_name), ft_strlen(sd->d_name));
		ft_lstadd(name_list, tmp);
	}
	closedir(dir);
}
/*
	//store name to list;
	//tmp->content = ft_strdup(sd->d_name);
	//tmp->content_size = ft_strlen(sd->d_name);
	//ft_printf("content: %s\nsize: %i\n", tmp->content, (int)tmp->content_size);
*/

int main(int ac, char **av)
{
	t_list *name_list;

	name_list = NULL;
	if (ac == 1)
	{
 		opendir_getnames(&name_list, ".");
		printstrarray(sort_str_array(name_list));
/*-------test system ls--------------*/
		//ft_putendl("\n");
		//system ("ls");
		return (0);
	}
	opendir_getnames(&name_list, av[1]);
	printstrarray(sort_str_array(name_list));
	return (0);
}
