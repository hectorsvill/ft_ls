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


int cstring_cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return (ft_strcmp(*ia, *ib));
    /**
    ** strcmp fx works exactly as
    ** expected from comparison fx.
    */
}

int main(int ac, char **av)
{
    //char *strings[] = {"bne", "dtwo", "afive", "look"};
    if (ac == 1)
    {
        ft_putendl(av[0]);
        return (0);
    }
   // int l = ac - 1;

    qsort(av, ac, sizeof(char*), cstring_cmp); //ft_qsort!!!
    printstrarray(av);
    ft_putchar('\n');

    return (0);
}
