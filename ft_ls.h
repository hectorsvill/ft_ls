#ifndef FT_LS_H
#define FT_LS_H

# include "libft/inc/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

typedef enum s_flags
{
	LONG_FORMAT = 1,	//	-l
	RECURISIVE_LIST = 2, // 	-R
	ALL_DIRS = 4,		// -a
	REVERSE_ORDER = 8,	// -r
 	TIMEMODIFIED_SORT = 16,	//-t
}			t_flags;

typedef struct	s_files
{
	char			*file; //file name


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
void 	opendir_getnames(t_files **files, char *dir_name);




/*
**	ftls_list.c
*/
void 		print_list_dirs(t_dirs *dir_list);
void 		print_list(t_files *list);
void 		lstadd_files(t_files **head,char *file_name);
void 		lstadd_dirs(t_dirs **head, char *dir_name);
t_entries	entries_init(void);

/*
**	merge_sort.c
*/
void 	merge_sort(t_files **headref);

/*
**	none_ex.c
*/
void get_stat(t_files *file_list, t_dirs **dirs, t_files **none_ex);
void addto_file_list(char **av, t_files **file_list);

#endif
