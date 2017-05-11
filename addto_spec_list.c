/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addto_spec_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:02:57 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/18 18:03:29 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void addto_list(char **av, t_entries *ent)
{
	struct stat sb;


	ent->dirs = NULL;
	ent->file_list = NULL;
	ent->none_ex = NULL;
	while (*av)
	{
		if (!ft_strcmp(*av, "--"))
			;
		else if ((stat(*av, &sb)) == -1)
			lstadd_files(&ent->none_ex, ".", *av, ent->flags);
		else if (S_ISREG(sb.st_mode))
			lstadd_files(&ent->file_list, ".", *av, ent->flags);
		else if(S_ISDIR(sb.st_mode))
			lstadd_dirs(&ent->dirs, *av, ent->flags);
		av++;
	}
}

t_dirs *add_too_dirlist(t_files *files, t_flags flag)
{
	t_dirs *d;

	d = NULL;

	while (files)
	{
		if (S_ISDIR(files->mode))
			lstadd_dirs(&d, files->file, flag);
		files = files->next;
	}
	return (d);
}
