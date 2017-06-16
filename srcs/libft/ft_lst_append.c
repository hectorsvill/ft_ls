#include "libft.h"

void 	ft_lst_append(t_list **alst, t_list *new_lst)
{
	t_list *tmp;

	if (!alst || !new_lst)
		return ;
	tmp = *alst;
	if (!*alst)
		*alst = new_lst;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lst;
	}
}
