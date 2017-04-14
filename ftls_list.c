#include "ft_ls.h"

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
