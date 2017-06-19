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

void		error_message(char *filename, char *error_msg_prefix, int close)
{
	ft_putstr_fd(filename, 2);
	perror(error_msg_prefix);
	if (close)
		exit(EXIT_FAILURE);
}

void		unknown_option(char c)
{
	ft_putstr_fd("ft_ls: illegal option --", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ft_ls [-alrRt] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}


void		calc_col_width_get_dev_info(t_list *file_list, unsigned int *w)
{
	t_file		*tmp;

	ft_bzero(w, sizeof(int) * 7);
	while (file_list)
	{
		tmp = (t_file *)file_list->content;
		w[0] = MAX(ft_intmax_tlen(tmp->stats.st_nlink), w[0]);
		if (getpwuid(tmp->stats.st_uid))
			w[1] = MAX(ft_strlen(getpwuid(tmp->stats.st_uid)->pw_name), w[1]);
		else
			w[1] = MAX(ft_strlen(ft_itoa(tmp->stats.st_uid)), w[1]);
		if (getgrgid(tmp->stats.st_gid))
			w[2] = MAX(ft_strlen(getgrgid(tmp->stats.st_gid)->gr_name), w[2]);
		else
			w[2] = MAX(ft_strlen(ft_itoa(tmp->stats.st_gid)), w[2]);
		w[3] = MAX(ft_intmax_tlen(tmp->stats.st_size), w[3]);
		w[4] = MAX(ft_intmax_tlen(tmp->stats.st_rdev >> 24), w[4]);
		w[5] = MAX(ft_intmax_tlen(tmp->stats.st_rdev & 0xFFFFFF), w[5]);
		w[6] = (((tmp->stats.st_mode & S_IFMT) == S_IFBLK) ||
				((tmp->stats.st_mode & S_IFMT) == S_IFCHR) ? 1 : 0);
		file_list = file_list->next;
	}
	w[0]++;
}
