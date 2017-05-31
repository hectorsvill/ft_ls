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

// void getmax_nbr(t_files *files, int *max, char section)
// {
// 	int size;
//
// 	size = 0;
// 	while (files)
// 	{
// 		if (section == 'n')
// 			size = ft_intmax_tlen((intmax_t)files->nlink);
// 		else if (section == 's')
// 			size = ft_intmax_tlen((intmax_t)files->size);
// 		else if (section == 'u')
// 			size = ft_strlen(files->uid);
// 		else if (section == 'g')
// 			size = ft_strlen(files->gid);
// 		if (size > *max)
// 			*max = size;
// 		files = files->next;
// 	}
// }
//
// void printfileslist(t_files *list, t_flags flags)
// {
// 	int nlinkmax = 0;
// 	int sizemax = 0;
// 	int uidmax = 0;
// 	int gidmax = 0;
//
// 	if (flags & LONG_FORMAT || flags & GROUP_NAME)
// 	{
// 		getmax_nbr(list, &nlinkmax, 'n');
// 		getmax_nbr(list, &sizemax, 's');
// 		getmax_nbr(list, &uidmax, 'u');
// 		getmax_nbr(list, &gidmax, 'g');
// 	}
// 	while (list)
// 	{
// 		if (flags & LONG_FORMAT || flags & GROUP_NAME)
// 			printlongformat(*list, nlinkmax, uidmax, gidmax, sizemax, flags);
// 		else
// 			ft_putendl(list->file);
// 		list = list->next;
// 	}
// }
//
//
// void print_all_dirs(t_dirs *dir_list, t_flags flags)
// {
// 	while (dir_list)
// 	{
// 		ft_printf("%s:\n", dir_list->dir_name);
// 		if (flags & LONG_FORMAT || flags & GROUP_NAME)
// 			ft_printf("total %i\n", gettotalblocks(dir_list->files));
// 		printfileslist(dir_list->files, flags);
// 		if (dir_list->next != NULL)
// 			write(1, "\n", 1);
// 		dir_list = dir_list->next;
// 	}
// }
//
// int opendir_getnames(t_files **files, char *dir_name, t_flags flags)
// {
//
// 	DIR             *dir;
// 	struct dirent   *sd;
//
// 	*files = NULL;
//
// 	if (!(dir = opendir(dir_name)))
// 	{
// 		ft_printf("ls: %s", dir_name);
// 		perror(": ");
// 		return (0);
// 	}
// 	while ((sd = readdir(dir)) != NULL)
// 		lstadd_files(files, dir_name, sd->d_name, flags);
// 	closedir(dir);
// 	return (1);
// }

t_bol file_accessible(char *file)
{
	struct stat st;

	if (lstat(file, &st) == 0)
		return (1);
	else
	{
		ft_printf("ft_ls: %s: %s", file, strerror(errno));
		return (0);
	}
}

void error_flag(char c)
{
	ft_putstr_fd("ft_ls: illegal option --", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ft_ls [-alrRtg] [file ....]\n", 2);
	exit(EXIT_FAILURE);
}

static t_flags *getallflags(int ac, char **av)
{
	t_flags	*flags;
	int		i;
	int		j;

	flags = ft_memalloc(sizeof(t_flags));
	i = 0;
	while (++i < ac)
	{

		j = 0;
		while (av[i][0] == '-' && av[i][j++] != '\0')
		{
			if (!ft_strchr("alrRtg", av[i][j]))
				error_flag(av[i][j]);
			flags->a = (av[i][j] == 'a') ? 1 : flags->a;
			flags->l = (av[i][j] == 'l') ? 1 : flags->l;
			flags->r = (av[i][j] == 'r') ? 1 : flags->r;
			flags->up_r = (av[i][j] == 'R') ? 1 : flags->up_r;
			flags->t = (av[i][j] == 't') ? 1 : flags->t;
			flags->g = (av[i][j] == 'g') ? 1 : flags->g;
		}
	}
	return (flags);
}

static t_list	get_filelist(int ac, char *av, int *valid_avs)
{
	t_list		*file_list;
	t_file		*tmp;
	int 		i;

	i = 0;
	file_list = NULL;
	tmp = (t_file*)ft_memalloc(sizeof(t_file))
	//file_list = get_valid_files(ac, av, &valid_avs);

	return (file_list);
}

int main (int ac, char **av)
{
	t_flags *flags;
	t_list 	*file_list;
	int		valid_avs;

	flags = getallflags(ac, av);
	file_list = get_filelist(ac, av, &valid_avs);
	free((void*)flags);
	return (0);
}

// int main(int ac, char **av)
// {
// 	t_entries ent;
//
//
//
// 	ent = entries_init();
// 	if (ac == 1)
// 	{
// 		/**
// 		**	When no arguments pressent open current directory
// 		**/
// 		ent.dirs->dir_name = ft_strdup(".");
//  		opendir_getnames(&ent.dirs->files, ent.dirs->dir_name, ent.flags);
// 		mergesort_files(&ent.dirs->files, ent.flags);
// 		printfileslist(ent.dirs->files, ent.flags);
// 		return (0);
// 	}
// 	else
// 		av++;
//
// 	if (**av == '-')
// 	{
// 		ent.flags = getallflags(av);
// 		if (ac == 2)
// 		{
// 			ent.dirs->dir_name = ft_strdup("./");
// 			opendir_getnames(&ent.dirs->files, ent.dirs->dir_name, ent.flags);
// 			mergesort_files(&ent.dirs->files, ent.flags);
// 			if (ent.flags & RECURISIVE_LIST)
// 			{
// 				t_dirs *d;
// 				char	*rd;
//
//
// 				printfileslist(ent.dirs->files, ent.flags);
// 				d = add_too_dirlist(ent.dirs->files, ent.flags);
// 				mergesort_dirs(&d, ent.flags);
// 				while (d)
// 				{
// 					rd = ft_strjoin(ent.dirs->dir_name, d->dir_name);
// 					ft_printf("\n%s:\n", rd);
// 					recursiveprint(rd, ent.flags);//printalldirsrec(rd, ent.flags);
// 					d = d->next;
// 				}
// 			}
// 			else
// 			{
//
// 				if (ent.flags & TIMEMODIFIED_SORT)
// 					mergesort_ltmod(&ent.dirs->files);
// 				if (ent.flags & LONG_FORMAT)
// 					ft_printf("total %i\n", gettotalblocks(ent.dirs->files));
// 				printfileslist(ent.dirs->files, ent.flags);
//
// 			}
//
// 		}
// 		else if (ac > 2)
// 		{
// 			av++;
// 			addto_list(av, &ent);
// 			mergesort_files(&ent.file_list, ent.flags);
// 			mergesort_dirs(&ent.dirs, ent.flags);
// 			if (ent.flags & TIMEMODIFIED_SORT)
// 			{
//
// 				mergesort_ltmod(&ent.file_list);
// 				mergesort_ltmod_dirs(&ent.dirs);
// 			}
// 			mergesort_files(&ent.none_ex, ent.flags);
// 			print_error_none_ex(ent.none_ex);
// 			printfileslist(ent.file_list, ent.flags);
//
// 			if (ent.dirs != NULL)
// 			{
// 				if (ent.file_list != NULL)
// 					ft_putchar('\n');
// 				if (ent.dirs->next == NULL)
// 				{
// 					if (ent.flags & LONG_FORMAT)
// 						ft_printf("total %i\n", gettotalblocks(ent.dirs->files));
// 					if (ent.flags & TIMEMODIFIED_SORT)
// 						mergesort_ltmod(&ent.dirs->files);
// 					else
// 						mergesort_files(&ent.dirs->files, ent.flags);
//
// 					if (ent.flags & RECURISIVE_LIST)
// 					{
// 						if (ent.none_ex != NULL || ent.file_list != NULL)
// 						 	ft_printf("%s:\n", ent.dirs->dir_name);
// 						recursiveprint(ent.dirs->dir_name, ent.flags);
// 					}
// 					else
// 						printfileslist(ent.dirs->files, ent.flags);
// 				}
// 				else
// 				{
// 					if (ent.flags & RECURISIVE_LIST)
// 						printalldirsrec(ent.dirs, ent.flags);
// 					else
// 						print_all_dirs(ent.dirs, ent.flags);
// 				}
// 			}
//
// 		}
//
// 	}
// 	else
// 	{
// 		/**
// 		**	only go in if no flags only file names
// 		**	check if file_list is valid else if not valid insert into none_ex
// 		**	file names are now in file_list and none existent in none_ex
// 		**/
// 		addto_list(av, &ent);
// 		mergesort_dirs(&ent.dirs, ent.flags);
// 		mergesort_files(&ent.file_list, ent.flags);
// 		mergesort_files(&ent.none_ex, ent.flags);
// 		print_error_none_ex(ent.none_ex);
// 		printfileslist(ent.file_list, ent.flags);
// 		if (ent.dirs != NULL)
// 		{
// 			if (ent.file_list != NULL)
// 				ft_putchar('\n');
// 			if (ac == 2)
// 			{
// 				opendir_getnames(&ent.dirs->files, *av, ent.flags);
// 				mergesort_files(&ent.dirs->files, ent.flags);
// 				printfileslist(ent.dirs->files, ent.flags);
// 			}
// 			else
// 				print_all_dirs(ent.dirs, ent.flags);
// 		}
// 	}
// 	return (0);
// }
