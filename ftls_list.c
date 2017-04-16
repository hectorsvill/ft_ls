#include "ft_ls.h"

void print_list_noflags(t_files *list)
{
	while (list)
	{
		/**if flag a is not on**/
		if (ft_strncmp(list->file, ".", 1))
			ft_putendl(list->file);
		list = list->next;
	}
}

void print_error_none_ex(t_files *none_ex)
{
	while (none_ex)
	{
		ft_printf("ls: %s: No such file or directory\n", none_ex->file);
		none_ex = none_ex->next;
	}
}

void print_all_dirs(t_dirs *dir_list)
{
	//first print all invalid files
	while (dir_list)
	{
		ft_printf("%s:\n", dir_list->dir_name);
		print_list_noflags(dir_list->files);
		ft_putchar('\n');
		dir_list = dir_list->next;
	}
}

void lstadd_dirs(t_dirs **head, char *dir_name)
{
	/**
	**	Add function to open directory and set
	**	t_files within t_dirs
	**/
	t_dirs *t_new;

	t_new = (t_dirs*)malloc(sizeof(t_dirs));
	t_new->dir_name = ft_strdup(dir_name);
	opendir_getnames(&t_new->files, dir_name);
	merge_sort(&t_new->files);
	t_new->next = *head;
	*head = t_new;
}

void lstadd_files(t_files **head, char *file_name)
{
	/**
	**	creat new link t_new and set file name
	**	link head to new link.
	**/
	t_files *t_new;

	t_new = (t_files*)malloc(sizeof(t_files));
	t_new->file = ft_strdup(file_name);
	t_new->next = *head;
	*head = t_new;
}

t_entries entries_init(void)
{
	t_entries entries;

	entries.dirs = (t_dirs*)malloc(sizeof(t_dirs));
	entries.dirs->files = (t_files*)malloc(sizeof(t_files));
	entries.file_list = (t_files*)malloc(sizeof(t_files));
	entries.none_ex = (t_files*)malloc(sizeof(t_files));
	return (entries);
}
