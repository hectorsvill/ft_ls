#include "ft_ls.h"

int file_accessible(char *file)
{
	struct stat st;

	if (lstat(file, &st) == 0)
		return (1);
	else
	{
		ft_printf("ft_ls: %s: %s\n", file, strerror(errno));
		return (0);
	}
}


void calc_col_width_get_dev_info(t_list *file_list, unsigned int *w)
{
	t_file *tmp;

	ft_bzero(w, sizeof(int) * 7);
	while (file_list)
	{
		tmp = (t_file *)file_list->content;
		w[0] = MAX(ft_intmax_tlen(tmp->stats.st_uid), w[0]);
		if (getpwuid(tmp->stats.st_uid))
			w[1] = MAX(ft_strlen(getpwuid(tmp->stats.st_uid)->pw_name), w[1]);


		file_list = file_list->next;
	}
}
