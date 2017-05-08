#include "ft_ls.h"






void 	rec(char *dir_name, t_dirs **head, t_flags flags)
{
	struct stat		sb;
	DIR 			*dir;
	struct dirent	*sd;
	char			tmp[256];




	//ft_bzero((void*)tmp, sizeof(tmp));
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
//	t_entries entr;
	t_dirs 	*dirs;
	t_dirs	*free_d;

	dirs = NULL;
	dirs = ft_memalloc(sizeof(t_dirs));
	dirs->dir_name = NULL;
	dirs->stmtime = 0;
	dirs->files = ft_memalloc(sizeof(t_files));
	dirs->files->file = NULL;
	dirs->files->uid = NULL;
	dirs->files->gid = NULL;
	dirs->files->mtime = NULL;
	dirs->files->lnklocstr = NULL;


	dirs->dir_name = ft_strdup(rootdir);
	opendir_getnames(&dirs->files, rootdir, flags);
	rec(rootdir, &dirs, flags);
	mergesort_dirs(&dirs, flags);
	mergesort_files(&dirs->files, flags);

	free_d = dirs;

	printfileslist(dirs->files, flags);
	ft_putchar('\n');
	dirs = dirs->next;

	print_all_dirs(dirs, flags);
}

void printalldirsrec(t_dirs *head, t_flags flags)
{
	// if (flags)
	// {}

	while (head)
	{
		ft_printf("\n%s:\n", head->dir_name);
		recursiveprint(head->dir_name, flags);
		head = head->next;
		//free_dirs(head);
	}
}

/*
void free_files(t_files *files)
{
	t_files *f_tmp;
	t_files *node;

	node = files;
	while (node)
	{
		f_tmp = node;
		node = node->next;
		free((void*)f_tmp->file);
		free((void*)f_tmp->uid);
		free((void*)f_tmp->gid);
		free((void*)f_tmp->mtime);
		free((void*)f_tmp->lnklocstr);
	}
	files = NULL;
}

void free_dirs(t_dirs *dirs)
{
	t_dirs	*d_tmp;
	t_dirs	*node;

	node = dirs;
	while (node)
	{
		d_tmp = node;
		node = node->next;
		free((void*)d_tmp->dir_name);
		//free_files(d_tmp->files);
		free((void*)d_tmp);
	}
	dirs = NULL;
}

*/
