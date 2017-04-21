/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:04:44 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/18 18:04:45 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void print_list_noflags(t_files *list)
{
	while (list)
	{
		/**if flag a is not on**/
/*		if (!(ALL_DIRS & flags))
		{	if (ft_strncmp(list->file, ".", 1))
				ft_putendl(list->file);
		}
		else */
			ft_putendl(list->file);
		list = list->next;
	}
}

void print_all_dirs(t_dirs *dir_list)
{
	while (dir_list)
	{
		ft_printf("%s:\n", dir_list->dir_name);
		print_list_noflags(dir_list->files);
		if (dir_list->next != NULL)
			write(1, "\n", 1);
		dir_list = dir_list->next;
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


/**
**	Add function to open directory and set
**	t_files within t_dirs
**/
void lstadd_dirs(t_dirs **head, char *dir_name, t_flags flags)
{
	t_dirs *t_new;


	t_new = (t_dirs*)malloc(sizeof(t_dirs));
	t_new->dir_name = ft_strdup(dir_name);
	opendir_getnames(&t_new->files, dir_name, flags);
	mergesort_files(&t_new->files);
	t_new->next = *head;
	*head = t_new;
}

void lstadd_files(t_files **head, char *file_name, t_flags flags)
{
	t_files		*t_new;
	struct stat	sb;

	if(!(flags & ALL_DIRS) && *file_name == '.')
	{

		return ;
	}

	lstat(file_name, &sb);
	t_new = (t_files*)malloc(sizeof(t_files));
	t_new->file = ft_strdup(file_name);
	t_new->st_mode = sb.st_mode;

	/**
	**	TODO: If the -l flag is pressent collect additional attributes.
	**			!Need to the t_flags in here!
	**/


	/*LINK*/
	t_new->next = *head;
	*head = t_new;
}

t_entries entries_init(void)
{
	t_entries entries;

	entries.flags = 0;
	entries.dirs = (t_dirs*)malloc(sizeof(t_dirs));
	entries.dirs->files = (t_files*)malloc(sizeof(t_files));
	//init dir->files
	entries.dirs->files->st_mode = 0;
	entries.file_list = (t_files*)malloc(sizeof(t_files));
	entries.none_ex = (t_files*)malloc(sizeof(t_files));
	return (entries);
}
