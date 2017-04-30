/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:04:32 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/24 14:19:08 by n                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
➜  ft_ls git:(master) ✗ ls -l
total 144
-rw-r--r--  1 hvillasa  august    764 Apr 26 13:15 recursiveprint.c
-rw-r--r--  1 hvillasa  august   1792 Apr 26 23:55 valid_flags.c
*/

void getmax_nbr(t_files *files, int *max, char section)
{
	int size;

	size = 0;
	while (files)
	{
		if (section == 'n')
			size = ft_intmax_tlen((intmax_t)files->nlink);
		else if (section == 's')
			size = ft_intmax_tlen((intmax_t)files->size);
		else if (section == 'u')
			size = ft_strlen(files->uid);
		else if (section == 'g')
			size = ft_strlen(files->gid);
		if (size > *max)
			*max = size;
		files = files->next;
	}
}

void printfileslist(t_files *list, t_flags flags)
{
	int nlinkmax = 0;
	int sizemax = 0;
	int uidmax = 0;
	int gidmax = 0;

	if (LONG_FORMAT & flags)
	{
		getmax_nbr(list, &nlinkmax, 'n');
		getmax_nbr(list, &sizemax, 's');
		getmax_nbr(list, &uidmax, 'u');
		getmax_nbr(list, &gidmax, 'g');
	}
	while (list)
	{
		if (LONG_FORMAT & flags)
			printlongformat(*list, nlinkmax, uidmax, gidmax, sizemax);
		else
			ft_putendl(list->file);
		list = list->next;
	}
}


void print_all_dirs(t_dirs *dir_list, t_flags flags)
{
	while (dir_list)
	{
		ft_printf("%s:\n", dir_list->dir_name);
		if (flags & LONG_FORMAT)
			ft_printf("total %i\n", gettotalblocks(dir_list->files));
		printfileslist(dir_list->files, flags);
		if (dir_list->next != NULL)
			write(1, "\n", 1);
		dir_list = dir_list->next;
	}
}

int opendir_getnames(t_files **files, char *dir_name, t_flags flags)
{

	DIR             *dir;
	struct dirent   *sd;

	*files = NULL;

	if (!(dir = opendir(dir_name)))
	{
		ft_printf("ft_ls: %s: ", dir_name);
		perror("");
		return (0);
	}
	while ((sd = readdir(dir)) != NULL)
		lstadd_files(files, dir_name, sd->d_name, flags);
	closedir(dir);
	return (1);
}

int main(int ac, char **av)
{
	t_entries ent;
	char flagcheck;

	flagcheck = 0;
	ent = entries_init();
	if (ac == 1)
	{
		/**
		**	When no arguments pressent open current directory
		**/
		ent.dirs->dir_name = ft_strdup(".");
 		opendir_getnames(&ent.dirs->files, ent.dirs->dir_name, ent.flags);
		mergesort_files(&ent.dirs->files);
		printfileslist(ent.dirs->files, ent.flags);
		return (0);
	}
	else
		av++;

	if (**av == '-')
	{
		flagcheck = checkflags(*av);
		if (flagcheck == 1)
			ent.flags = setfield(*av);
		else
		{
			if (flagcheck != '1')
			{
				ft_printf("ft_ls: illegal option -- %c\n", flagcheck);
				ft_putendl("usage: ft_ls [-lRart] [file ...]");
				exit(1);
			}
		}
		if (ac == 2)
		{
			ent.dirs->dir_name = ft_strdup(".");
			opendir_getnames(&ent.dirs->files, ent.dirs->dir_name, ent.flags);
			if (ent.flags & TIMEMODIFIED_SORT)
				mergesort_ltmod(&ent.dirs->files);
			else
				mergesort_files(&ent.dirs->files);

			//if (ent.flags & RECURISIVE_LIST)
			//	recursiveprint(ent);
			//else
			if (ent.flags & LONG_FORMAT)
				ft_printf("total %i\n", gettotalblocks(ent.dirs->files));
			printfileslist(ent.dirs->files, ent.flags);
		}
		else if (ac > 2)
		{
			av++;
			//ft_putendl(*av);exit(2);
			addto_list(av, &ent);
			if (ent.flags & TIMEMODIFIED_SORT)
				mergesort_ltmod(&ent.file_list);
			else
				mergesort_files(&ent.file_list);
			mergesort_files(&ent.none_ex);
			mergesort_dirs(&ent.dirs);
			print_error_none_ex(ent.none_ex);
			printfileslist(ent.file_list, ent.flags);
			if (ent.dirs != NULL)
			{
				if (ent.file_list != NULL)
					ft_putchar('\n');
				if (ent.dirs->next == NULL)
				{
					if (ent.flags & LONG_FORMAT)
						ft_printf("total %i\n", gettotalblocks(ent.dirs->files));
					opendir_getnames(&ent.dirs->files, *av, ent.flags);
					if (ent.flags & TIMEMODIFIED_SORT)
						mergesort_ltmod(&ent.dirs->files);
					else
						mergesort_files(&ent.dirs->files);
					printfileslist(ent.dirs->files, ent.flags);
				}
				else
					print_all_dirs(ent.dirs, ent.flags);
			}
		/*	if ((ent.dirs != NULL) && (ent.flags & RECURISIVE_LIST))
				recursiveprint(ent);
			else if (ent.dirs != NULL)
				printfileslist(ent.dirs->files, ent.flags);
		*/
		}

	}
	else
	{
		/**
		**	only go in if no flags only file names
		**	check if file_list is valid else if not valid insert into none_ex
		**	file names are now in file_list and none existent in none_ex
		**/
		addto_list(av, &ent);
		mergesort_dirs(&ent.dirs);
		mergesort_files(&ent.file_list);
		mergesort_files(&ent.none_ex);
		print_error_none_ex(ent.none_ex);
		printfileslist(ent.file_list, ent.flags);
		if (ent.dirs != NULL)
		{
			if (ent.file_list != NULL)
				ft_putchar('\n');
			if (ac == 2)
			{
				opendir_getnames(&ent.dirs->files, *av, ent.flags);
				mergesort_files(&ent.dirs->files);
				printfileslist(ent.dirs->files, ent.flags);
			}
			else
				print_all_dirs(ent.dirs, ent.flags);
		}
	}
	return (0);
}
