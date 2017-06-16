/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:33:32 by hvillasa          #+#    #+#             */
/*   Updated: 2017/06/02 13:33:35 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpush(t_list **head, void const *content, int len)
{
	t_list	*current;
	char	*tmp;

	tmp = NULL;
	if (*head == NULL)
	{
		tmp = ft_strdup(content);
		*head = ft_lstnew(tmp, len);
		free(tmp);
	}
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = (t_list*)malloc(sizeof(t_list));
		current->next->content = ft_strdup(content);
		current->next->content_size = len;
		current->next->next = NULL;
	}
}
