#include "ft_ls.h"

void printstrarray(char **av)
{
    int i;

    i = 0;
    while (av[i])
    {
        ft_putendl(av[i++]);

    }
}


int qsortstr_cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return (ft_strcmp(*ia, *ib));
    /**
    ** strcmp fx works exactly as
    ** expected from comparison fx.
    */
}

int get_list_len(t_list *name_list)
{
	int i;

	i = 0;
	while (name_list)
	{
		i++;
		name_list = name_list->next;
	}
	return (i);
}

char **get_name_array(size_t list_len, t_list *name_list)
{
	char **names;
	size_t i;

	names = (char**)malloc((list_len + 1) * sizeof(char*));
	i = 0;
	while (name_list)
	{
		names[i] = ft_strnew(name_list->content_size);
		ft_strncpy(names[i], name_list->content, name_list->content_size);
		name_list = name_list->next;
		i++;
	}
	names[i] = 0;
	return (names);
}

void sort_str_array(t_list *name_list)
{
	size_t list_len;
	char **names;

	list_len = get_list_len(name_list);
	names = get_name_array(list_len, name_list);
	//list_len += 1;
	qsort(names, list_len, sizeof(char*), qsortstr_cmp); //ft_qsort!!!
	printstrarray(names);
}
