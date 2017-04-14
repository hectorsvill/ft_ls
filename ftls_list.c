#include "ft_ls.h"

void print_list(t_files *list)
{
	int sp;
	sp = 0;
	while (list)
	{
		if (ft_strncmp(list->file_names, ".", 1))
			ft_putendl(list->file_names );
		//ft_putstr("    ");
		list = list->next;
	}

}

void ftls_lstadd(t_entries **alst, t_entries *t_new)
{
	t_new->next = *alst;
	*alst = t_new;
}

t_entries *ftls_lstnew_entries(char *name)
{
	t_entries *link;

	link = (t_entries*)malloc(sizeof(t_entries));
	link->files->file_names = ft_strdup(name);
	return (link);
}
