#include "ft_ls.h"

/*
	1.store directory names in array or link list.
	2.sort list of names with qsort.
	3.print list of names

*/

void ls_openprintdir(t_list *name_list, char *name)
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

	tmp = ft_lstnew("", 0);
	name_list = ft_lstnew("", 0);
	while ((sd = readdir(dir)) != NULL)
		if(ft_strncmp(sd->d_name, ".", 1) && ft_strcmp(sd->d_name, ".."))
		{
			//store name to list;
			tmp->content = sd->d_name;
			tmp->content_size = ft_strlen(sd->d_name);
			ft_printf("content: %s\nsize: %i\n", tmp->content, (int)tmp->content_size);
			ft_lstadd(&name_list, tmp);
		}


	closedir(dir);
}


int main(int ac, char **av)
{
	t_list *name_list;

	name_list = NULL;
    if (ac == 1)
    {
 		ls_openprintdir(name_list, ".");

		//check system ls
		ft_putendl("\n");
		system ("ls");

		return (0);
    }
	ls_openprintdir(name_list, av[1]);

	//sort_str_array(ac, av);
    return (0);
}
