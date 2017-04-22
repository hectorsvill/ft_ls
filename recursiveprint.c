#include "ft_ls.h"

void print_dirnames(t_dirs *head)
{

	while (head)
	{
		ft_putendl(head->dir_name);
		head = head->next;
	}
}

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
				lstadd_dirs(head, tmp, flags);

			rec(tmp, head, flags);
		}
	}
	closedir(dir);
	return ;
}
void 	recursiveprint(t_entries ent)
{
	char *rootdir = ent.dirs->dir_name;

	rec(rootdir, &ent.dirs, ent.flags);
	//print_dirnames(ent.dirs);
	mergesort_dirs(&ent.dirs);
	print_all_dirs(ent.dirs);
}
