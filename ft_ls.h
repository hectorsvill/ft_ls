#ifndef FT_LS_H
#define FT_LS_H

# include "libft/inc/ft_printf.h"
# include <sys/types.h>
# include <dirent.h>

typedef struct	s_ftls
{
	char			*names;

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
