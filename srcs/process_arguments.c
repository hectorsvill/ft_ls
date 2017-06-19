#include "ft_ls.h"

static void		print_blocks(t_list *file_list)
{
	blkcnt_t	total;
	int			blksize;

	total = 0;
	if (file_list)
		blksize = ((t_file *)file_list->content)->stats.st_blksize / 1024;
	while (file_list)
	{
		total += ((t_file *)file_list->content)->stats.st_blocks;
		file_list = file_list->next;
	}
	ft_printf("total %zu blocks (%ukb blocksize)\n", total, blksize);
}

static void print_dir_contents(t_list *parent, t_list *file_list, t_flags *flags)
{
	t_list			*entries;
	t_list			*tmp_entries;
	unsigned int	info[7];

	if (!(entries = open_directory(parent, file_list, flags)))
		return ;
	if (flags->l)
		print_blocks(entries);
	ls_sort(entries, (flags->t) ? cmp_lex : cmp_alpha, flags->r);
	tmp_entries = entries;
	calc_col_width_get_dev_info(entries, info);
	while (entries)
	{
		if (flags->l)
			print_with_stats((t_file *)entries->content,
										((t_file *)file_list->content), info);
		else
			ft_printf("%s\n", ((t_file *)entries->content)->name);
		entries = entries->next;
	}
	entries = tmp_entries;
	if (flags->up_r)
		traverse_subdirectories(entries, file_list, flags);
}

void 	traverse_subdirectories(t_list *entries, t_list *file_list, t_flags *flags)
{
	while (entries)
	{
		if (S_ISDIR(((t_file*)entries->content)->stats.st_mode) &&
				!ft_strequ(((t_file*)entries->content)->name, ".") &&
				!ft_strequ(((t_file*)entries->content)->name, ".."))
			print_dir_contents(file_list, entries, flags);
		entries = entries->next;
	}
	ft_lstdel(&entries, ft_lst_free);
}


static void process_dir_contents(t_list *file_list, t_flags *flags, t_list *prev, int list_length)
{
	if (!ft_strequ(".", ((t_file *)file_list->content)->name))
	{
		if (prev)
			ft_putchar('\n');
		if (list_length > 1)
			ft_printf("%s:\n", ((t_file *)file_list->content)->name);
	}
	print_dir_contents(NULL, file_list, flags);
}

void process_arguments(t_list *file_list, t_flags *flags, int list_len)
{
	t_list			*prev;
	unsigned int	info[7];

	prev = NULL;
	calc_col_width_get_dev_info(file_list, info);
	while(file_list)
	{
		if (S_ISDIR(((t_file *)file_list->content)->stats.st_mode))
			process_dir_contents(file_list, flags, prev, list_len);
		else
		{
			if (flags->l)
				print_with_stats((t_file*)file_list->content, NULL, info);
			else
				ft_printf("%s\n", ((t_file*)file_list->content)->name);
		}
		prev = file_list;
		file_list = file_list->next;
	}

}
