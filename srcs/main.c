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

static t_flags		*read_options(int ac, char **av)
{
	int		i;
	int		j;
	t_flags	*flags;

	flags = ft_memalloc(sizeof(t_flags));
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][0] == '-' && av[i][j++] != '\0')
		{
			if (!ft_strchr("alrRt", av[i][j]))
				unknown_option(av[i][j]);
			flags->a = (av[i][j] == 'a' ? 1 : flags->a);
			flags->l = (av[i][j] == 'l' ? 1 : flags->l);
			flags->r = (av[i][j] == 'r' ? 1 : flags->r);
			flags->up_r = (av[i][j] == 'R' ? 1 : flags->up_r);
			flags->t = (av[i][j] == 't' ? 1 : flags->t);
		}
	}
	return (flags);
}

static t_list		*populate_valid_args(int ac, char **av, int *valid_args)
{
	int			i;
	t_list		*file_list;
	t_file		*tmp;

	i = 0;
	file_list = NULL;
	tmp = (t_file *)ft_memalloc(sizeof(t_file));
	while (++i < ac)
	{
		if (av[i][0] != '-' && !file_accessible(av[i]))
		{
			//ft_printf("ft_ls: %s: %s", av[i], strerror(errno));
			(*valid_args)++;
		}
		else if (ft_strchr(&av[i][0], '-') == 0 &&
		!ft_strequ(av[i], "./ft_ls"))
		{
			tmp->name = ft_strdup(av[i]);
			lstat(tmp->name, &(tmp->stats));
			ft_lst_append(&file_list, ft_lstnew(tmp, sizeof(t_file)));
			(*valid_args)++;
		}
	}
	free(tmp);
	return (file_list);
}

static	t_list		*init_list_from_args(int ac, char **av, t_flags *flags)
{
	t_list		*file_list;
	t_file		*tmp;
	int			valid_args;

	valid_args = 0;
	tmp = (t_file *)ft_memalloc(sizeof(t_file));
	file_list = populate_valid_args(ac, av, &valid_args);
	if (valid_args == 0 && !ft_lst_len(file_list))
	{
		tmp->name = ft_strdup(".");
		lstat(tmp->name, &(tmp->stats));
		ft_lst_append(&file_list, ft_lstnew(tmp, sizeof(t_file)));
	}
	else
		ls_sort(file_list, (flags->t ? &cmp_lex : &cmp_alpha), flags->r);
	free(tmp);
	return (file_list);
}

int					main(int ac, char **av)
{
	t_flags		*flags;
	t_list		*file_list;
	int			list_length;

	flags = read_options(ac, av);
	file_list = init_list_from_args(ac, av, flags);

	list_length = ft_lst_len(file_list);
	process_arguments(file_list, flags, list_length);
	ft_lstdel(&file_list, &ft_lst_free);
	free(flags);
	return (0);
}
