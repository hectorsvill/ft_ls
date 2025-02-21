# ft_ls
ft_ls
# DESCRIPTION
List directory contents

## main

```c
int  main(int ac, char **av)
{
	t_flags		*flags;
	t_list		*file_list;
	int		list_length;

	flags = read_options(ac, av);
	file_list = init_list_from_args(ac, av, flags);

	list_length = ft_lst_len(file_list);
	process_arguments(file_list, flags, list_length);
	ft_lstdel(&file_list, &ft_lst_free);
	free(flags);
	return (0);
}

```
