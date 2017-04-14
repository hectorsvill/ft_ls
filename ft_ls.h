#ifndef FT_LS_H
#define FT_LS_H

# include "libft/inc/ft_printf.h"
# include <sys/types.h>
# include <dirent.h>

typedef enum s_flags
{
	long_format = 1,	//	-l
	recursive_list = 2, // 	-R
	all_dirs = 4,		// -a
	reverse_order = 8,	// -r
 	timemodified_sort = 16,	//-t
	//all_flags_on =
}			t_flags;

typedef struct	s_ftls
{
	char		*names;
	char		flags;

	struct s_ftls	*next;
}				t_ftls;

/*
**	ftls_list.c
*/
void 	print_list(t_ftls *list);
void 	ftls_lstadd(t_ftls **alst, t_ftls *t_new);
t_ftls 	*ftls_lstnew(char *name);
/*
**	merge_sort.c
*/
void 	merge_sort(t_ftls **headref);
/*
**
*/

#endif
