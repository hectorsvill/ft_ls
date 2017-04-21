/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:04:32 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/18 18:04:33 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_ls.h"

/*
	1.store directory names in link list.
	2.sort list of names with merge sort.
	3.print list of names

*/


int opendir_getnames(t_files **files, char *dir_name, t_flags flags)
{

	DIR             *dir;
	struct dirent   *sd;

	*files = NULL;
	if (!(dir = opendir(dir_name)))
		return (0);
	/**
	**	make this function return 0
	**	if dir_name is invalid directory
	**	if invalid d irectory then send to entries.none_ex
	**/
	while ((sd = readdir(dir)) != NULL)
		lstadd_files(files, sd->d_name, flags);
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
		ent.dirs->dir_name = ".";
 		opendir_getnames(&ent.dirs->files, ".", ent.flags);
		mergesort_files(&ent.dirs->files);
		printfileslist(ent.dirs->files);
		return (0);
	}
	else
		av++;

	if (**av == '-')
	{
		/**
		**	TODO: Only enter when Flags are pressent.
		*/
		if (!ft_strcmp(*av, "-")){
			ft_putendl("ls: -: No such file or directory");
			return (0);
		}
		/**
		**	TODO: Store flag information into t_flags.
		**/
		flagcheck = checkflags(*av);
		if (flagcheck == 1)
		{
			ent.flags = setfield(*av);
			//ft_printf("t_flags:%i\n", ent.flags);
		}
		else
		{
			ft_printf("ls: illegal option -- %c\n", flagcheck);
			ft_putendl("usage: ls [-lRart] [file ...]");
		}

		/**
		**	TODO: if ac > 2 not NULL
		**		  store files and folders in proper list
		**/
		if (ac > 2)
		{
			//collect files
			av++;
			addto_list(av, &ent);
			//sort
			mergesort_files(&ent.file_list);
			mergesort_files(&ent.none_ex);
			//print
			print_error_none_ex(ent.none_ex);
			//printfileslist(ent.file_list, ent.flags);
			if (ac == 4 && ent.dirs != NULL)
				printfileslist(ent.dirs->files);
			else
			{
				/**
				**	TODO:	Check if -R is set
				**		 	if is set Dir walk!
				**/

				if (ent.flags & RECURISIVE_LIST)
				{
					//recursiveprint(&ent);
				}

				//print_all_dirs(ent.dirs, ent.flags);
			}
		}
		else if (ac == 2)
		{
			/**
			**	open dir get names
			**/
			ent.dirs->dir_name = ft_strdup(".");
			opendir_getnames(&ent.dirs->files, ".", ent.flags);
			mergesort_files(&ent.dirs->files);
			if (ent.flags & RECURISIVE_LIST)
				recursiveprint(ent);
			else
				printfileslist(ent.dirs->files);
		}
	}
	else
	{
		/**
		**	only go in if no flags only file names
		**	check if file_list is valid else if not valid insert into none_ex
		**	file names are now in file_list and none existent in none_ex
		**/
		//add to list
		addto_list(av, &ent);
		//sort
		mergesort_dirs(&ent.dirs);
		//if (ent.dirs != NULL)
			//mergesort_files(&ent.dirs->files);
		mergesort_files(&ent.file_list);
		mergesort_files(&ent.none_ex);

		//make this into funtion
		print_error_none_ex(ent.none_ex);
		printfileslist(ent.file_list);
		print_all_dirs(ent.dirs);
	}
	return (0);
}


/*
		ft_putendl("\nfile_list:");
		printfileslist(entries.file_list);
		ft_putendl("");

		ft_putendl("\nnone_ex:");
		printfileslist(entries.none_ex);
		ft_putendl("");



		ft_putendl("\ndir->files:");
		print_all_dirs(entries.dirs);
		ft_putendl("");
*/
