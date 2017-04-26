#include "ft_ls.h"

void 	rec(char *dir_name, t_dirs **head)
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
				lstadd_dirs(head, tmp);

			rec(tmp, head);
		}
	}
	closedir(dir);
	return ;
}

void 	recursiveprint(t_entries ent)
{
	char *rootdir;

	rootdir = ent.dirs->dir_name;
	rec(rootdir, &ent.dirs);
	mergesort_dirs(&ent.dirs);
	print_all_dirs(ent.dirs, ent.flags);
}
