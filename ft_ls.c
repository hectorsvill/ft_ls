#include "libft/inc/ft_printf.h"
#include <sys/types.h>
#include <dirent.h>

void ls_print_dir(char *name)
{
    /**
    **  This fx writes a list of the directory name
    */
    DIR             *dir;
    struct dirent   *sd;

    dir = opendir(name);
    if (!dir)
        ft_printf("Error: Unable to open directory");
    else
    {
        while ((sd = readdir(dir)) != NULL)
            if(ft_strncmp(sd->d_name, ".", 1) && ft_strcmp(sd->d_name, ".."))
                ft_printf("%s ", sd->d_name);
    }
    closedir(dir);
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        ls_print_dir(".");
        ft_putchar('\n');    
        return (0);
    }
    ls_print_dir(av[1]);
    ft_putchar('\n');
    return (0);
}

