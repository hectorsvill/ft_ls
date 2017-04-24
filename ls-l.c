#include "ft_ls.h"
#include <stdio.h>


char *file_mtime(const time_t *timer)
{
	char *s;

	s = ft_strdup(ctime(timer));

	return (s);
}

char *fileprotection(short st_mode)
{
	char *str;

	str = ft_strnew(10);
	str[0] = (S_ISDIR(st_mode) ? 'd' : '-');
	str[1] = (st_mode & S_IRUSR ? 'r' : '-');
	str[2] = (st_mode & S_IWUSR ? 'w' : '-');
	str[3] = (st_mode & S_IXUSR ? 'x' : '-');
	str[4] = (st_mode & S_IRGRP ? 'r' : '-');
	str[5] = (st_mode & S_IWGRP ? 'w' : '-');
	str[6] = (st_mode & S_IXGRP ? 'x' : '-');
	str[7] = (st_mode & S_IROTH ? 'r' : '-');
	str[8] = (st_mode & S_IWOTH ? 'w' : '-');
	str[9] = (st_mode & S_IXOTH ? 'x' : '-');
	return (str);
}
/*


-rw-------   1 bshotts  bshotts       576 Apr 17  1998 weather.txt
drwxr-xr-x   6 bshotts  bshotts      1024 Oct  9  1999 web_page
-rw-rw-r--   1 bshotts  bshotts    276480 Feb 11 20:41 web_site.tar
-rw-------   1 bshotts  bshotts      5743 Dec 16  1998 xmas_file.txt

----------     -------  -------  -------- ------------ -------------
    |             |        |         |         |             |
    |             |        |         |         |         File Name
    |             |        |         |         |
    |             |        |         |         +---  Modification Time
    |             |        |         |
    |             |        |         +-------------   Size (in bytes)
    |             |        |
    |             |        +-----------------------        Group
    |             |
    |             +--------------------------------        Owner
    |
    +----------------------------------------------   File Permissions







➜  ft_ls git:(master) ✗ ls -l
total 108
-rw-rw-r-- 1 n n  1402 Apr 22 19:05 addto_spec_list.c
-rwxrwxr-x 1 n n 49176 Apr 23 08:50 ft_ls
-rw-rw-r-- 1 n n  2440 Apr 22 19:05 ft_ls.h
-rw-rw-r-- 1 n n  2280 Apr 22 19:05 ftls_list.c
drwxrwxr-x 5 n n  4096 Apr 23 08:12 libft
-rw-rw-r-- 1 n n  3904 Apr 23 08:49 main.c
-rw-r--r-- 1 n n  5024 Apr 22 19:44 main.o
-rw-rw-r-- 1 n n  1306 Apr 23 07:33 Makefile
-rw-rw-r-- 1 n n  2240 Apr 22 19:05 mergesort_dirs.c
-rw-rw-r-- 1 n n  2167 Apr 22 19:05 mergesort_files.c
-rw-rw-r-- 1 n n   922 Apr 23 07:33 recursiveprint.c
drwxr-xr-x 4 n n  4096 Apr 22 19:33 testdir
drwxr-xr-x 5 n n  4096 Apr 23 08:13 testdir1
-rw-rw-r-- 1 n n  1791 Apr 22 19:05 valid_flags.c
➜  ft_ls git:(master) ✗


*/
