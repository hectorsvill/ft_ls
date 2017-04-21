#include "ft_ls.h"

void print_dirnames(t_dirs *head)
{

	while (head)
	{
		ft_putendl(head->dir_name);
		head = head->next;
	}
}


void recursiveprint(t_entries ent)
{
	t_files *files;

	files = ent.dirs->files;
	while (files)
	{
		ft_putendl(files->file);
		files = files->next;
	}
}
