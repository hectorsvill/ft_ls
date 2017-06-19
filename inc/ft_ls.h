/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:04:53 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/24 13:53:5«3 by n                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

# include "ft_printf.h"
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>


typedef struct	s_flags
{
	unsigned int l:1;
	unsigned int up_r:1;
	unsigned int a:1;
	unsigned int r:1;
	unsigned int t:1;
	unsigned int g:1;
}				t_flags;

typedef struct	s_file
{
	char 		*name;
	struct stat	stats;
}				t_file;

/**
** ls_help.c
**/
int 	file_accessible(char *file);
void	calc_col_width_get_dev_info(t_list *file_list, unsigned int *w);
void	unknown_option(char c);
void	error_message(char *filename, char *error_msg_prefix, int close);
/**
** sort.c
**/
void 	ls_sort(t_list *start, int (*f)(t_file*, t_file *, int), int reverse_cmp);
int		cmp_alpha(t_file *p1, t_file *p2, int reverse_cmp);
int		cmp_lex(t_file *p1, t_file *p2, int reverse_cmp);
/**
** process_arguments.c
**/
void process_arguments(t_list *file_list, t_flags *flags, int list_len);
void 	traverse_subdirectories(t_list *entries, t_list *file_list, t_flags *flags);
//
// typedef struct	s_files
// {
// 	char		*file;
// 	char		fileprotection[10];
// 	char		*uid;
// 	char		*gid;
// 	char		*mtime;
// 	char		*lnklocstr;
// 	time_t		stmtime;
// 	short		mode;
// 	long		size;
// 	long		nlink;
// 	int			blocks;
// 	struct s_files	*next;
// }				t_files;
//
// typedef struct	s_dirs
// {
// 	char		*dir_name;		//name of specific dir
// 	t_files		*files; //files of this dir_name
// 	time_t		stmtime;
// 	struct s_dirs	*next;
// }				t_dirs;
//
// typedef struct s_entries
// {
// 	t_dirs		*dirs;	//hold list of dirs
// 	t_files		*file_list; //hold list of files to output
// 	t_files		*none_ex; //holds files that are non existent
// 	t_flags		flags;
// }				t_entries;

/**
**	main.c
**/

// int 	opendir_getnames(t_files **files, char *dir_name, t_flags flags);
//
// /*
// **	ftls_list.c
// */
//
// void 		print_all_dirs(t_dirs *dir_list, t_flags flags);
// void 		printfileslist(t_files *list, t_flags flags);
//
// void 		print_error_none_ex(t_files *none_ex);
//
// void 		lstadd_files(t_files **head, char *dir_name, char *file_name, t_flags flags);
// void 		lstadd_dirs(t_dirs **head, char *dir_name, t_flags flags);
// t_entries	entries_init(void);
// /**
// **	mergesort_files.c
// **/
// void 	mergesort_files(t_files **headref, t_flags flags);
// /**
// **	mergesort_dirs.c
// **/
// void 	mergesort_dirs(t_dirs **headref, t_flags flags);
// /**
// **	addto_spec_list.c
// **/
// t_dirs 	*add_too_dirlist(t_files *files, t_flags flag);
// void 	addto_list(char **av, t_entries *ent);
// /**
// **	mergesort_ltmodified.c
// **/
// void 	mergesort_ltmod(t_files **headref);
// void 	mergesort_ltmod_dirs(t_dirs **headref);
/*
**	valid_flags.c
*/

// char 	checkflags(char *cf);
// t_flags setfield(char *str_flags);

// /*
// **	recursiveprint.c
// */
// void 	recurthisdir(t_dirs *dirs, t_flags flags);
// void 	recursiveprint(char *rootdir, t_flags flags);
// void 	printalldirsrec(t_dirs *head, t_flags flags);
// t_dirs 	*init_d(void);
// /*
// **	ls-l.c
// */
//
// int		gettotalblocks(t_files *files);
// char	*fileprotection(short st_mode);
// char	*file_mtime(time_t *timer);
// void 	printlongformat(t_files file, int nlinkmax, int uidmax, int gidmax, int sizemax, t_flags);
// char	*get_uid(uid_t sb_uid);
// char	*get_gid(gid_t sb_gid);
//



#endif
