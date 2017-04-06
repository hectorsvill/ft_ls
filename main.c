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

int main(void)
{
    DIR *dir;
    struct dirent *sd;

    dir = opendir(".");

    if (!dir)
    {
        ft_printf("Error: Unable to open directory");
        return (0);
    }
    while ((sd = readdir(dir)) != NULL)
        ft_printf("%s\n", sd->d_name);
    closedir(dir);
    return (0);
}

