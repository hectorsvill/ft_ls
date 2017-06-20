#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/types.h>




void writeformatsp(int len)
{
	while (len > 0)
	{
		ft_putchar(' ');
		len--;
	}
}
void printlongformat(t_files file, int nlinkmax, int uidmax, int gidmax, int sizemax, t_flags flags)
{
	int len;

	len = 0;
	ft_printf("%s  ", file.fileprotection);
	len  = (int)ft_intmax_tlen((intmax_t)file.nlink);
	writeformatsp(nlinkmax - len);
	ft_printf("%i ", file.nlink);

	if (!(flags & GROUP_NAME))
	{
		ft_printf("%s  ", file.uid);
		len = (int)ft_strlen(file.uid);
		writeformatsp(uidmax - len);
	}
	ft_printf("%s  ", file.gid);
	len = (int)ft_strlen(file.gid);
	writeformatsp(gidmax - len);
	len  = ft_intmax_tlen((intmax_t)file.size);
	writeformatsp(sizemax - len);
	ft_printf("%li ", file.size);
	ft_printf("%s ", file.mtime);
	if (S_ISLNK(file.mode))
	{
		ft_putstr(file.file);
		ft_putstr(" -> ");
		ft_putendl(file.lnklocstr);
	}
	else
		ft_putendl(file.file);


//	ft_printf("%s  %li %s  %s  %li %s %s\n", file.fileprotection,
//		file.nlink, file.uid, file.gid, file.size, file.mtime, file.file);
}

int	gettotalblocks(t_files *files)
{
	int total;

	total = 0;
	while (files)
	{
		total += files->blocks;
		files = files->next;
	}
	return (total);
}

char		*file_mtime(time_t *timer)
{
	char	*sctime;
	char	*new_stime;
	time_t	tnow;

	sctime = ctime(timer);
	tnow = time(NULL);
	sctime += 4;
	new_stime = ft_strnew(12);
	if (*timer < (tnow - 15780000) || *timer > (tnow + 15780000))
	{
		//Oct 21 12:33:00 2016
		ft_strncpy(new_stime, sctime, 7);
		sctime += 15;
		ft_strncat(new_stime, sctime, 5);
	}
	else
		ft_strncpy(new_stime, sctime, 12);
	return (new_stime);
}

char		*get_uid(uid_t sb_uid)
{
	struct passwd	*pwd;
	char			*str;

	pwd = getpwuid(sb_uid);
	str = ft_strdup(pwd->pw_name);
	return (str);
}
char		*get_gid(gid_t sb_gid)
{
	struct group	*grp;
	char			*str;

	grp = getgrgid(sb_gid);
	str = ft_strdup(grp->gr_name);
	return (str);
}

char 		*fileprotection(short st_mode)
{
	char *str;

	str = ft_strnew(10);
	if (S_ISDIR(st_mode))
		str[0] = 'd';
	else if (S_ISLNK(st_mode))
		str[0] = 'l';
	else
		str[0] = '-';
	str[1] = st_mode & S_IRUSR ? 'r' : '-';
	str[2] = st_mode & S_IWUSR ? 'w' : '-';
	str[3] = st_mode & S_IXUSR ? 'x' : '-';
	str[4] = st_mode & S_IRGRP ? 'r' : '-';
	str[5] = st_mode & S_IWGRP ? 'w' : '-';
	str[6] = st_mode & S_IXGRP ? 'x' : '-';
	str[7] = st_mode & S_IROTH ? 'r' : '-';
	str[8] = st_mode & S_IWOTH ? 'w' : '-';
	str[9] = st_mode & S_IXOTH ? 'x' : '-';
	return (str);
}
