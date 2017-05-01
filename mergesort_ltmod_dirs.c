/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_dirs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:04:12 by hvillasa          #+#    #+#             */
/*   Updated: 2017/04/18 18:04:13 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_ls.h"

/**
**	split nodes into  front and back halves,
**	and return two list with a and b.
**	if list is odd extra node goes in front list.
**	look up fast slow pointer strategy.
**/
static void 	frontbacksplit(t_dirs *source, t_dirs **frontref,
	t_dirs **backref)
{
	t_dirs		*fast;
	t_dirs		*slow;

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

static t_dirs	*sortedmerge(t_dirs *a, t_dirs *b)
{
	t_dirs		*result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->stmtime > b->stmtime)
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
/**
**	I need a merge sort for dir_names!
**	or just keep order in file_list!
**/
void 			mergesort_ltmod_dirs(t_dirs **headref)
{
	t_dirs		*head;
	t_dirs		*a;
	t_dirs		*b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontbacksplit(head, &a, &b);
	mergesort_ltmod_dirs(&a);
	mergesort_ltmod_dirs(&b);
	*headref = sortedmerge(a, b);
}
