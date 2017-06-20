#include "libft.h"

void ft_lst_free(void *content, size_t content_size)
{
	content_size = 0;
	if (content)
		free(content);
}
