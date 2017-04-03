/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:33:01 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/17 06:36:27 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	link = (t_list*)malloc(sizeof(t_list) * content_size);
	if (link)
	{
		if (content)
		{
			link->content_size = content_size;
			link->content = (t_list*)malloc(content_size);
			if (link->content)
				ft_memmove(link->content, content, content_size);
		}
		else
		{
			link->content = NULL;
			link->content_size = 0;
		}
		link->next = NULL;
	}
	return (link);
}
