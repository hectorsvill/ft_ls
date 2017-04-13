#ifndef FT_LS_H
#define FT_LS_H

# include "libft/inc/ft_printf.h"
# include <sys/types.h>
# include <dirent.h>



char 	**sort_str_array(t_list *name_list);
void 	printstrarray(char **av);
void 	merge_sort(t_list **headref);

#endif
