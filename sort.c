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

char **sort_str_array(int ac, char **av)
{
    qsort(av, ac, sizeof(char*), qsortstr_cmp); //ft_qsort!!!
    printstrarray(av);
    ft_putchar('\n');

    return (av);
}
