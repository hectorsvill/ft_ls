#include "ft_ls.h"


void 	rec(char *dir_name, t_dirs **head, t_flags flags)
{
	struct stat		sb;
	DIR 			*dir;
	struct dirent	*sd;
	char			tmp[256];




	ft_bzero((void*)tmp, sizeof(tmp));
	if (!(dir = opendir(dir_name)))
		return ;

	while ((sd = readdir(dir)))
	{
		if (!ft_strcmp(sd->d_name, ".") || !ft_strcmp(sd->d_name, ".."))
			continue ;
		if (ft_strncmp(sd->d_name, ".", 1))
		{

			ft_strcpy(tmp,dir_name);
			ft_strcat(tmp, "/");
			ft_strcat(tmp, sd->d_name);
			stat(tmp, &sb);
			if (S_ISDIR(sb.st_mode))
			{
				if (!dir_name)
					return ;
				lstadd_dirs(head, tmp, flags);
			}

			rec(tmp, head, flags);
		}
	}
	closedir(dir);
	return ;
}

void  	recursiveprint(char *rootdir, t_flags flags)
{
	t_entries entr;

	entr = entries_init();

	entr.dirs->dir_name = ft_strdup(rootdir);
	opendir_getnames(&entr.dirs->files, rootdir, flags);
	rec(rootdir, &entr.dirs, flags);
	mergesort_dirs(&entr.dirs, flags);
	mergesort_files(&entr.dirs->files, flags);
	printfileslist(entr.dirs->files, flags);
	entr.dirs = entr.dirs->next;
	ft_putchar('\n');
	print_all_dirs(entr.dirs, flags);
}

void printalldirsrec(t_dirs *head, t_flags flags)
{
	while (head)
	{
		recursiveprint(head->dir_name, flags);
		head = head->next;
	}
}
