#include "libft/inc/ft_printf.h"

void printstrarray(char **av)
{
    int i;

    i = 0;
    while (av[i])
        ft_printf("%s ",av[i++]);
}


int cstring_cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return (ft_strcmp(*ia, *ib));
    /**
    ** strcmp functions works exactly as
    ** expected from comparison fx.
    */
}

int main(int ac, char **av)
{
    if (ac == 100)
    {
        ft_putendl(av[0]);
    }
   // printstrarray(av);
    
    char *strings[] = {"bne", "dtwo", "afive"};
    
    qsort(strings, 3, sizeof(char*), cstring_cmp);
    printstrarray(strings);
    ft_putchar('\n');
    return (0);
}