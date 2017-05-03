/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:04:44 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/24 14:08:11 by n                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void print_error_none_ex(t_files *none_ex)
{
	while (none_ex)
	{
		if (!ft_strcmp(none_ex->file, "-1"))
			;
		else
			ft_printf("ls: %s: No such file or directory\n", none_ex->file);
		none_ex = none_ex->next;
	}
}

void lstadd_dirs(t_dirs **head, char *dir_name, t_flags flags)
{
	t_dirs *t_new;
	struct stat sb;
	t_new = (t_dirs*)malloc(sizeof(t_dirs));
	t_new->dir_name = ft_strdup(dir_name);

	lstat(dir_name, &sb);

	t_new->stmtime = sb.st_mtime;
	opendir_getnames(&t_new->files, t_new->dir_name, flags);
	if (flags & TIMEMODIFIED_SORT)
		mergesort_ltmod(&t_new->files);
	else
		mergesort_files(&t_new->files, flags);
	t_new->next = *head;
	*head = t_new;
}

void lstadd_files(t_files **head, char *dir_name, char *file_name, t_flags flags)
{
	t_files		*t_new;
	struct stat	sb;
	char		*path;

	if(!(flags & ALL_DIRS) && *file_name == '.')
	{
		if (!ft_strncmp(file_name, "../", 3))
			;
		else
			return ;
	}
	path = ft_strnew(ft_strlen(dir_name) + ft_strlen(file_name) + 1);
	ft_strcpy(path, dir_name);
	ft_strcat(path, "/");
	ft_strcat(path, file_name);
	t_new = (t_files*)malloc(sizeof(t_files));
	t_new->file = ft_strdup(file_name);
	if (lstat(path, &sb) != -1)
	{
		if (S_ISLNK(sb.st_mode))
		{
			t_new->lnklocstr = (char*)malloc(sb.st_size + 1);
			readlink(path, t_new->lnklocstr, sb.st_size);
		}
		t_new->mode = (short)sb.st_mode;
		t_new->size = (long)sb.st_size;
		t_new->mtime = file_mtime(&sb.st_mtime);
		t_new->nlink = sb.st_nlink;
		t_new->stmtime = sb.st_mtime;
		ft_strcpy(t_new->fileprotection, fileprotection(sb.st_mode));
		t_new->uid = get_uid(sb.st_uid);
		t_new->gid = get_gid(sb.st_gid);
		t_new->blocks = (int)sb.st_blocks;
	}
	t_new->next = *head;
	*head = t_new;
}

t_entries entries_init(void)
{
	t_entries ent;

	ent.flags = (t_flags)0;
	ent.dirs = (t_dirs*)malloc(sizeof(t_dirs));
	ent.dirs->files = (t_files*)malloc(sizeof(t_files));
	//init dir->files
	ent.dirs->files->uid = NULL;
	ent.dirs->files->gid = NULL;
	ent.dirs->files->lnklocstr = NULL;
	ent.file_list = (t_files*)malloc(sizeof(t_files));
	ent.none_ex = (t_files*)malloc(sizeof(t_files));
	return (ent);
}
