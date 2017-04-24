/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:04:53 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/24 08:12:39 by n                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

# include "libft/inc/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

typedef enum s_flags
{
	LONG_FORMAT = 1,		//	-l
	RECURISIVE_LIST = 2, 	// 	-R
	ALL_DIRS = 4,			// -a
	REVERSE_ORDER = 8,		// -r
 	TIMEMODIFIED_SORT = 16,	//-t
}			t_flags;

typedef struct	s_files
{
	char		*file; //file name
	short		st_mode;
	char		fileprotection[10];
	long		st_size;
	struct s_files	*next;
}				t_files;

typedef struct	s_dirs
{
	char			*dir_name;		//name of specific dir
	t_files			*files; //files of this dir_name




	struct s_dirs	*next;
}				t_dirs;

typedef struct s_entries
{
	t_dirs		*dirs;	//hold list of dirs
	t_files		*file_list; //hold list of files to output
	t_files		*none_ex; //holds files that are non existent
	t_flags		flags;
}				t_entries;

/**
**	main.c
**/

int 	opendir_getnames(t_files **files, char *dir_name, t_flags flags);

/*
**	ftls_list.c
*/

void 		print_all_dirs(t_dirs *dir_list);
void 		printfileslist(t_files *list);

void 		print_error_none_ex(t_files *none_ex);

void 		lstadd_files(t_files **head,char *file_name, t_flags flags);
void 		lstadd_dirs(t_dirs **head, char *dir_name, t_flags flags);
t_entries	entries_init(void);

/**
**	mergesort_files.c
**/
void 	mergesort_files(t_files **headref);
/**
**	mergesort_dirs.c
**/
void 	mergesort_dirs(t_dirs **headref);
/*
**	addto_spec_list.c
*/
void 	addto_list(char **av, t_entries *ent);
/*
**	valid_flags.c
*/
char 	checkflags(char *cf);
t_flags setfield(char *str_flags);

/*
**	recursiveprint.c
*/
void 	recursiveprint(t_entries ent);
/*
**	ls-l.c
*/
char *fileprotection(short st_mode);
#endif
