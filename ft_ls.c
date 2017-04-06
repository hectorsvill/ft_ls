#include "libft/inc/ft_printf.h"
#include <sys/types.h>
#include <dirent.h>

void ls_openprintdir(char *name)
{
    /**
    **  This fx writes a list of the directory name
    */
    DIR             *dir;
    struct dirent   *sd;

    dir = opendir(name);
    if (!dir)
        ft_printf("ls: cannot access %s: No such file or directory\n", name);
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
        ls_openprintdir(".");
        return (0);
    }
    ls_openprintdir(av[1]);
    return (0);
}

