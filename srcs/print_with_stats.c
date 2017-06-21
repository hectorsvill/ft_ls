







#include "ft_ls.h"



static void		print_time(time_t mod_time)
{
	char	*str;
	char	*start;
	char	*end;
	time_t	ct;

	ct = time(NULL);
	if ((str = ctime(&mod_time)) == NULL)
		return ;
	start = str + 4;
	end = str + 10;
	*end = 0;
	ft_putstr(start);
	ft_putchar(' ');
	start = (mod_time > ct || mod_time + SIX_MONTHS < ct) ?
	str + 20 : str + 11;
	end = (mod_time > ct || mod_time + SIX_MONTHS < ct) ?
	str + 24 : (end = str + 16);
	if (mod_time > ct || mod_time + SIX_MONTHS < ct)
		ft_putchar(' ');
	*end = 0;
	ft_putstr(start);
}


static void		print_name_or_link(t_file *file, t_file *parent, mode_t mode)
{
	char		link_buf[1024];
	ssize_t		count;
	char		*path;

	if ((mode & S_IFMT) == S_IFLNK)
	{
		ft_bzero(link_buf, sizeof(link_buf));
		if (parent)
			path = ft_strjoin(parent->name, ft_strjoin("/", file->name));
		else
			path = ft_strdup(file->name);
		count = readlink(path, link_buf, sizeof(link_buf));
		if (count < 0)
		{
			free(path);
			perror("readlink");
			exit(EXIT_FAILURE);
		}
		link_buf[count] = '\0';
		ft_printf(" %s -> %s\n", file->name, link_buf);
		free(path);
	}
	else
		ft_printf(" %s\n", file->name);
}


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

void writeformatsp(int len)
{
	while (len > 0)
	{
		ft_putchar(' ');
		len--;
	}
}


void			print_with_stats(t_file *file, t_file *parent, unsigned int *i)
{
	int len;

	print_filetype(file->stats.st_mode);

	len  = (int)ft_intmax_tlen((intmax_t)file->stats.st_nlink);
	writeformatsp(i[0] - len);
	ft_printf(" %i ", file->stats.st_nlink);
	//if (!(flags & GROUP_NAME))
		ft_printf("%s  ", getpwuid(file->stats.st_uid)->pw_name);
		len = (int)ft_strlen(getpwuid(file->stats.st_uid)->pw_name);
		writeformatsp(i[1] - len);

	ft_printf("%s  ", getgrgid(file->stats.st_gid)->gr_name);
	len = (int)ft_strlen(getgrgid(file->stats.st_gid)->gr_name);
	writeformatsp(i[2] - len);

	len  = ft_intmax_tlen((intmax_t)file->stats.st_size);
	writeformatsp(i[3] - len);
	ft_printf("%li ", file->stats.st_size);

	print_time(file->stats.st_mtime);
	print_name_or_link(file, parent, file->stats.st_mode);
}
