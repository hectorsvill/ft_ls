#include "ft_ls.h"

void print_dirnames(t_dirs *head)
{

	while (head)
	{
		ft_putendl(head->dir_name);
		head = head->next;
	}
}

void 	recursiveprint(char *dir_name)//, t_dirs **head)
{
	DIR 			*dir;
	struct dirent	*sd;
	char			tmp[256];

	ft_bzero((void*)tmp, sizeof(tmp));
	if (!(dir = opendir(dir_name)))
		return ;
	ft_printf("DIR: %s\n",  dir_name);
	while ((sd = readdir(dir)))
	{
		if (!ft_strcmp(sd->d_name, ".") || !ft_strcmp(sd->d_name, ".."))
			continue ;
		if (ft_strncmp(sd->d_name, ".", 1))
		{
			ft_strcpy(tmp,dir_name);
			ft_strcat(tmp, "/");
			ft_strcat(tmp, sd->d_name);
			recursiveprint(tmp);
		}
	}
	closedir(dir);
	return ;
}
