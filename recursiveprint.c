/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursiveprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:17:49 by hvillasa          #+#    #+#             */
/*   Updated: 2017/05/10 17:17:58 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs *init_d(void)
{
	t_dirs *dirs;

	dirs = ft_memalloc(sizeof(t_dirs));
	dirs->dir_name = NULL;
	dirs->stmtime = 0;
	dirs->files = ft_memalloc(sizeof(t_files));
	dirs->files->file = NULL;
	dirs->files->uid = NULL;
	dirs->files->gid = NULL;
	dirs->files->mtime = NULL;
	dirs->files->lnklocstr = NULL;
	dirs->dir_name = NULL;
	return (dirs);
}

void 	rec(char *dir_name, t_dirs **head, t_flags flags)
{
	struct stat		sb;
	DIR 			*dir;
	struct dirent	*sd;
	char			tmp[256];

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

void printalldirsrec(t_dirs *head, t_flags flags)
{
	while (head)
	{
		ft_printf("\n%s:\n", head->dir_name);
		recursiveprint(head->dir_name, flags);
		head = head->next;
	}
}

void  	recursiveprint(char *rootdir, t_flags flags)
{
	t_dirs 	*dirs;
	//t_dirs	*head;

	dirs = init_d();
	dirs->dir_name = ft_strdup(rootdir);
	opendir_getnames(&dirs->files, rootdir, flags);
	mergesort_files(&dirs->files, flags);
	printfileslist(dirs->files, flags);
	dirs = dirs->next;
	rec(rootdir, &dirs, flags);
	mergesort_dirs(&dirs, flags);
	ft_putchar('\n');
	print_all_dirs(dirs, flags);
}
