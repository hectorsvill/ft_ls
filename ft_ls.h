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


char 	**sort_str_array(t_ftls *name_list);
void 	merge_sort(t_ftls **headref);

#endif
