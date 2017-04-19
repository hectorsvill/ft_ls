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


int opendir_getnames(t_files **files, char *dir_name)
{

    DIR             	*dir;
    struct dirent   	*sd;

	*files = NULL;
	if (!(dir = opendir(dir_name)))
		return (0);
	/**
	**	make this function return 0
	**	if dir_name is invalid directory
	**	if invalid d irectory then send to entries.none_ex
	**/

	while ((sd = readdir(dir)) != NULL)
		lstadd_files(files, sd->d_name);
	closedir(dir);
	return (1);
}

int main(int ac, char **av)
{
	t_entries entries;
	char flagcheck;

	flagcheck = 0;
	entries = entries_init();
	if (ac == 1)
	{
		entries.dirs->dir_name = ".";
 		opendir_getnames(&entries.dirs->files, ".");
		mergesort_files(&entries.dirs->files);
		print_list_noflags(entries.dirs->files, entries.flags);
		return (0);
	}
	else
		av++;
	if (**av == '-')
	{
		/**
		**	TODO: When Flags are pressent.
		**
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
			entries.flags = setfield(*av);
			//ft_printf("t_flags:%i\n", entries.flags);
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
			addto_list(av, &entries);
			//sort
			mergesort_files(&entries.file_list);
			mergesort_files(&entries.none_ex);
			//print
			print_error_none_ex(entries.none_ex);
			//print_list_noflags(entries.file_list, entries.flags);
			if (ac == 4 && entries.dirs != NULL)
				print_list_noflags(entries.dirs->files, entries.flags);
			else
			{
				/**
				**	TODO:	Check if -R is set
				**		 	if is set Dir walk!
				**/

				if (entries.flags & RECURISIVE_LIST)
				{
					//recursiveprint(&entries);
				}

				//print_all_dirs(entries.dirs, entries.flags);
			}
		}
		else if (ac == 2)
		{
			entries.dirs->dir_name = ".";
			opendir_getnames(&entries.dirs->files, ".");
			mergesort_files(&entries.dirs->files);
			if (entries.flags & RECURISIVE_LIST)
				recursiveprint(&entries);
			else
				print_list_noflags(entries.dirs->files, entries.flags);
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
		addto_list(av, &entries);
		//sort
		mergesort_dirs(&entries.dirs);
		//if (entries.dirs != NULL)
			//mergesort_files(&entries.dirs->files);
		mergesort_files(&entries.file_list);
		mergesort_files(&entries.none_ex);

		//make this into funtion
		print_error_none_ex(entries.none_ex);
		print_list_noflags(entries.file_list, entries.flags);
		print_all_dirs(entries.dirs, entries.flags);
	}
	return (0);
}


/*
		ft_putendl("\nfile_list:");
		print_list_noflags(entries.file_list);
		ft_putendl("");

		ft_putendl("\nnone_ex:");
		print_list_noflags(entries.none_ex);
		ft_putendl("");



		ft_putendl("\ndir->files:");
		print_all_dirs(entries.dirs);
		ft_putendl("");
*/
