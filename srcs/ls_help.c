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
