#include "libft/inc/ft_printf.h"
#include <sys/types.h>
#include <dirent.h>
/*
**  List files in current directory:
*/
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

