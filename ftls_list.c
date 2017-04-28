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
			ft_printf("ft_ls: %s: No such file or directory\n", none_ex->file);
		none_ex = none_ex->next;
	}
}

void lstadd_dirs(t_dirs **head, char *dir_name)
{
	t_dirs *t_new;

	t_new = (t_dirs*)malloc(sizeof(t_dirs));
	t_new->dir_name = ft_strdup(dir_name);
	t_new->next = *head;
	*head = t_new;
}

void lstadd_files(t_files **head, char *file_name, t_flags flags)
{
	t_files		*t_new;
	char		*lnklocstr;
	struct stat	sb;


	lnklocstr = NULL;
	if(!(flags & ALL_DIRS) && *file_name == '.')
	{
		if (!ft_strncmp(file_name, "../", 3))
			;
		else
			return ;
	}
	lstat(file_name, &sb);
	t_new = (t_files*)malloc(sizeof(t_files));
	t_new->file = ft_strdup(file_name);
	if (S_ISLNK(sb.st_mode))
	{
		lnklocstr = (char*)malloc(sb.st_size + 1);
		readlink(file_name, lnklocstr, sb.st_size);
		t_new->lnklocstr = ft_strdup(lnklocstr);
	}
	t_new->mode = (short)sb.st_mode;
	t_new->size = (long)sb.st_size;
	t_new->mtime = file_mtime(&sb.st_mtime);
	t_new->nlink = sb.st_nlink;
	ft_strcpy(t_new->fileprotection, fileprotection(sb.st_mode));
	t_new->uid = get_uid(sb.st_uid);
	t_new->gid = get_gid(sb.st_gid);
	t_new->blocks = (int)sb.st_blocks;
	//printf("st_blocks: %li\n", t_new->blocks);//exit(2);

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
