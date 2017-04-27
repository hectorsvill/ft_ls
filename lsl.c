#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/types.h>

void printlongformat(t_files file)
{
	ft_printf("%s  %li %s  %s  %li %s %s\n", file.fileprotection,
		file.nlink, file.uid, file.gid, file.size, file.mtime, file.file);
}

int	gettotalblocks(t_files *files)
{
	int total;

	total = 0;
	while (files)
	{
//		ft_printf("%i\n", files->blocks);
		total += files->blocks;
		files = files->next;
	}
//	ft_printf("total = %i\n", total);exit(1);
	return (total);
}

char		*file_mtime(time_t *timer)
{
	char	*sctime;
	char	*new_stime;

	sctime = ctime(timer);
	sctime += 4;
	new_stime = ft_strnew(12);
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
	str[0] = S_ISDIR(st_mode) ? 'd' : '-';
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
