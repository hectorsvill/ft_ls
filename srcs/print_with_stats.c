







#include "ft_ls.h"

static void print_permissions(mode_t m)
{
	ft_putchar(m & S_IRUSR ? 'r' : '-');
	ft_putchar(m & S_IWUSR ? 'w' : '-');
	if (m & S_ISUID)
		ft_putchar(m & S_IXUSR ? 's' : 'S');
	else
		ft_putchar(m & S_IXUSR ? 'x' : '-');
	ft_putchar(m & S_IRGRP ? 'r' : '-');
	ft_putchar(m & S_IWGRP ? 'w' : '-');
	if (m & S_ISGID)
		ft_putchar(m & S_IXGRP ? 's' : 'S');
	else
		ft_putchar(m & S_IXGRP ? 'x' : '-');
	ft_putchar(m & S_IROTH ? 'r' : '-');
	ft_putchar(m & S_IWOTH ? 'w' : '-');
	if (m & S_ISVTX)
		ft_putchar(m & S_IXUSR ? 't' : 'T');
	else
		ft_putchar(m & S_IXOTH ? 'x' : '-');
}

void print_filetype(mode_t m)
{
	if (S_ISREG(m))
		ft_putchar('-');
	else if (S_ISSOCK(m))
		ft_putchar('s');
	else if (S_ISLNK(m))
		ft_putchar('l');
	else if (S_ISCHR(m))
		ft_putchar('c');
	else if (S_ISBLK(m))
		ft_putchar('b');
	else if (S_ISFIFO(m))
		ft_putchar('f');
	else if (S_ISDIR(m))
		ft_putchar('d');
	print_permissions(m);
	//ACL
}


void print_with_stats(t_file *file, t_file *parent, unsigned int *i)
{
	print_filetype(file->stats.st_mode);

}
