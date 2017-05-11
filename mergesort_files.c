/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:04:05 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/18 18:04:06 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_ls.h"

/**
**	split nodes into  front and back halves,
**	and return two list with a and b.
**	if list is odd extra node goes in front list.
**	look up fast slow pointer strategy.
**/
static void 	frontbacksplit(t_files *source, t_files **frontref,
	t_files **backref)
{
	t_files		*fast;
	t_files		*slow;

	if (source == NULL || source->next == NULL)
	{
		*frontref = source;
		*backref = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*frontref = source;
		*backref = slow->next;
		slow->next = NULL;
	}
}

static t_files	*sortedmerge(t_files *a, t_files *b)
{
	t_files		*result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->file, b->file) < 0)
	{
		result = a;
		result->next = sortedmerge(a->next , b);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next);
	}
	return (result);
}


static t_files	*sortedmerge_reverse(t_files *a, t_files *b)
{
	t_files		*result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->file, b->file) > 0)
	{
		result = a;
		result->next = sortedmerge_reverse(a->next , b);
	}
	else
	{
		result = b;
		result->next = sortedmerge_reverse(a, b->next);
	}
	return (result);
}

void 			mergesort_files(t_files **headref, t_flags flags)
{
	t_files		*head;
	t_files		*a;
	t_files		*b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontbacksplit(head, &a, &b);
	mergesort_files(&a, flags);
	mergesort_files(&b, flags);
	if (flags & REVERSE_ORDER)
		*headref = sortedmerge_reverse(a, b);
	else
		*headref = sortedmerge(a, b);
}
