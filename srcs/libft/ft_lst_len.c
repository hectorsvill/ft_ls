#include "libft.h"

size_t ft_lst_len(t_list *head)
{
	size_t len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}
