#include "ft_ls.h"



void ls_openprintdir(char *name)
{
    /**
    **  This fx writes a list of the directory name
    */
    DIR             *dir;
    struct dirent   *sd;

    dir = opendir(name);
    if (!dir)
	{
		ft_printf("ls: cannot access %s: No such file or directory\n", name);
		exit(1);
	}
    else
    {
        while ((sd = readdir(dir)) != NULL)
            if(ft_strncmp(sd->d_name, ".", 1) && ft_strcmp(sd->d_name, ".."))
            {
				ft_putendl(sd->d_name);
				//ft_putstr("  ");
			}
    }
    closedir(dir);
}


int main(int ac, char **av)
{
    if (ac == 1)
    {
      //  ls_openprintdir(".");
		//ft_putchar('\n');
		///system ("ls");
        return (0);
    }
    //ls_openprintdir(av[1]);
    
    sort_str_array(ac, av);
    return (0);
}
