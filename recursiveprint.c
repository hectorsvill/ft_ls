#include "ft_ls.h"

void print_dirnames(t_dirs *head)
{

	while (head)
	{
		ft_putendl(head->dir_name);
		head = head->next;
	}
}


t_dirs *find_dirs(t_files *files)
{
	t_dirs *head;
	struct stat sb;

	head = (t_dirs*)malloc(sizeof(t_dirs));
	head = NULL;
	while (files)
	{
		if (ft_strcmp(files->file, ".") > 0 && ft_strcmp(files->file, "..") > 0)
		{
			stat(files->file, &sb);
			if (S_ISDIR(sb.st_mode))
			{
				lstadd_dirs(&head, files->file);
				//ft_putendl(files->file);
			}
		}
		files = files->next;
	}
	return (head);
}



void recursiveprint(t_entries ent)
{
	t_dirs *tmp;

	tmp = find_dirs(ent.dirs->files);
	mergesort_dirs(&tmp);
	print_dirnames(tmp);
}
