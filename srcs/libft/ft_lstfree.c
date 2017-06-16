/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:40:02 by hvillasa          #+#    #+#             */
/*   Updated: 2017/06/02 13:40:11 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstfree(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		free(head->content);
		head = head->next;
		free(tmp);
	}
}
