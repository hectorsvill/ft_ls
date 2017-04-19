#include "ft_ls.h"


void find_dirs(t_files *files, t_dirs **head)
{

	struct stat sb;


	while (files)
	{
		if (ft_strcmp(files->file, ".") > 0 && ft_strcmp(files->file, "..") > 0)
		{
			stat(files->file, &sb);
			if (S_ISDIR(sb.st_mode)){
				lstadd_dirs(head, files->file);
				ft_putendl(files->file);
			}
		}
		files = files->next;
	}

}



void recursiveprint(t_entries *ent)
{
	//puts("here");
	//print_list_noflags(ent->dirs->files, ent->flags);
	find_dirs(ent->dirs->files, &ent->dirs);

}
