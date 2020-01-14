# ft_ls
ft_ls
DESCRIPTION
     For each operand that names a file of a type other than directory, ls displays its name as well as any
     requested, associated information.  For each operand that names a file of type directory, ls displays
     the names of files contained within that directory, as well as any requested, associated information.


## main

```
int  main(int ac, char **av)
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

```
