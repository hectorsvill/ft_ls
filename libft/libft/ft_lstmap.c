/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 06:00:37 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/17 06:22:25 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *iter_o;
	t_list *iter_n;

	new_lst = f(lst);
	if (new_lst)
	{
		iter_o = lst->next;
		iter_n = new_lst;
		while (iter_o)
		{
			iter_n->next = f(iter_o);
			iter_o = iter_o->next;
			iter_n = iter_n->next;
		}
	}
	return (new_lst);
}
