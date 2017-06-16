/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:04:32 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/24 14:19:08 by n                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void error_flag(char c)
{
	ft_putstr_fd("ft_ls: illegal option --", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ft_ls [-alrRtg] [file ....]\n", 2);
	exit(EXIT_FAILURE);
}

static t_flags *getallflags(int ac, char **av)
{
	t_flags	*flags;
	int		i;
	int		j;

	flags = ft_memalloc(sizeof(t_flags));
	i = 0;
	while (++i < ac)
	{

		j = 0;
		while (av[i][0] == '-' && av[i][j++] != '\0')
		{
			if (!ft_strchr("alrRtg", av[i][j]))
				error_flag(av[i][j]);
			flags->a = (av[i][j] == 'a') ? 1 : flags->a;
			flags->l = (av[i][j] == 'l') ? 1 : flags->l;
			flags->r = (av[i][j] == 'r') ? 1 : flags->r;
			flags->up_r = (av[i][j] == 'R') ? 1 : flags->up_r;
			flags->t = (av[i][j] == 't') ? 1 : flags->t;
			flags->g = (av[i][j] == 'g') ? 1 : flags->g;
		}
	}
	return (flags);
}

static t_list *get_valid_files(int ac, char **av, int *valid_files)
{
	t_list	*file_list;
	t_file	*tmp;
	int		i;

	i = 0;
	file_list = NULL;
	tmp = (t_file *)ft_memalloc(sizeof(t_file));
	while (++i < ac)
	{
		if (av[i][0] != '-' && !file_accessible(av[i]))
		{
			//ft_printf("ft_ls: %s: %s\n", av[i], strerror(errno));
			(*valid_files)++;
		}
		else //if(ft_strchr(&av[i][0], '-') == 0 && !ft_strequ(av[i], "./ft_ls"))
		{
			tmp->name = ft_strdup(av[i]);
			lstat(tmp->name, &(tmp->stats));
			//ft_lst_append(&file_list, ft_lstnew(tmp, sizeof(t_file)));
			(*valid_files)++;
		}
	}
	free(tmp);
	return (file_list);
}

static t_list	*get_filelist(int ac, char **av, t_flags *flags)
{
	t_list		*file_list;
	t_file		*tmp;
	int 		valid_avs;

	printf("%i\n", (int)flags);
	valid_avs = 0;
	tmp = (t_file*)ft_memalloc(sizeof(t_file));
	file_list = get_valid_files(ac, av, &valid_avs);
	// if (valid_files == 0 && !ft_lst_len(file_list))
	// {
	// 	tmp->name = ft_strdup(".");
	// 	lstat(tmp->name, &(tmp->stats));
	// 	ft_lst_append(&file_list, ft_lstnew(tmp, sizeof(t_file)));
	// }
	// else
	// 	lst_sort(file_list, (flag));
	// free(tmp);
	return (file_list);
}

int main (int ac, char **av)
{
	t_flags *flags;
	t_list 	*file_list;

	ft_printf("%-10.3s", "test, ");
	ft_putendl("");
	flags = getallflags(ac, av);
	file_list = get_filelist(ac, av, flags);
	while (file_list){
		ft_putendl((char*)file_list->content);
		file_list = file_list->next;
	}
	//free((void*)flags);
	return (0);
}
