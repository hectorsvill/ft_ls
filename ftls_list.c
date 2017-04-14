#include "ft_ls.h"

void print_list(t_files *list)
{
	while (list)
	{
		//if (ft_strncmp(list->file_names, ".", 1))
			ft_putendl(list->files);
		//ft_putstr("    ");
		list = list->next;
	}

}

void lstadd_dirs(t_dirs **alst, t_dirs *t_new)
{
	t_new->next = *alst;
	*alst = t_new;
}



void lstadd_files(t_files **head, char *file_name)
{
	t_files *t_new;

	t_new = (t_files*)malloc(sizeof(t_files));
	t_new->files = ft_strdup(file_name);

	t_new->next = *head;
	*head = t_new;
}


t_files *lstnew_files(char *name)
{
	t_files *file;

	file = (t_files*)malloc(sizeof(t_files));
	file->files = ft_strdup(name);
	file->next = NULL;
	return (file);
}
