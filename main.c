#include "libft/inc/ft_printf.h"
#include <sys/types.h>
#include <dirent.h>

/*
**  List files in current directory:
*/
/*
int main(void)
{
    struct dirent *dp;
    DIR *dfd = opendir(".");
    if(dfd != NULL)
    {
        while ((dp = readdir(dfd)) != NULL)
            ft_printf("%s\n", dp->d_name);
        closedir(dfd);
    }
    return (0);
}
*/

void ft_ls_no_flags(void)
{
    DIR *dir;
    struct dirent *sd;

    dir = opendir(".");
    if (!dir)
        ft_printf("Error: Unable to open directory");
    else
    {
        while ((sd = readdir(dir)) != NULL)
            if(ft_strncmp(sd->d_name, ".", 1) && ft_strcmp(sd->d_name, ".."))
                ft_printf("%s\n", sd->d_name);
    }
    closedir(dir);
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        ft_ls_no_flags();
        return (0);
    }
    ft_putchar(av[1][0]);
    ft_putchar('\n');
    return (0);
}

