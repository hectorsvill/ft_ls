#include "ft_ls.h"
#include <stdio.h>

char *fileprotection(short st_mode)
{
	char *str;

	str = ft_strnew(10);
	ft_strcat((char*)str, (S_ISDIR(st_mode) ? "d" : "-"));
	ft_strcat((char*)str, (st_mode & S_IRUSR ? "r" : "-"));
	ft_strcat((char*)str, (st_mode & S_IWUSR ? "w" : "-"));
	ft_strcat((char*)str, (st_mode & S_IXUSR ? "x" : "-"));
	ft_strcat((char*)str, (st_mode & S_IRGRP ? "r" : "-"));
	ft_strcat((char*)str, (st_mode & S_IWGRP ? "w" : "-"));
	ft_strcat((char*)str, (st_mode & S_IXGRP ? "x" : "-"));
	ft_strcat((char*)str, (st_mode & S_IROTH ? "r" : "-"));
	ft_strcat((char*)str, (st_mode & S_IWOTH ? "w" : "-"));
	ft_strcat((char*)str, (st_mode & S_IXOTH ? "x" : "-"));
	return (str);
}



/*

int main(int ac, char **av)
{
	struct stat sb;
	char 		*str;

	if(stat(av[1], &sb) < 0)
		return (0);


	ft_putendl(av[1]);
	str = fileprotection(sb.st_mode);


	ft_putendl("File Permission: ");
	ft_putendl(str);

	return (0);
}
*/


/*

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
