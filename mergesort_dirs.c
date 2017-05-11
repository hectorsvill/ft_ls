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
	if (ft_strcmp(a->dir_name, b->dir_name) < 0)
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


static t_dirs	*sortedmerge_reverse(t_dirs *a, t_dirs *b)
{
	t_dirs		*result = NULL;
	// char		*as;
	// char		*bs;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	//
	// as = a->dir_name;
	// bs = b->dir_name;
	// as += 2;
	// bs += 2;
	//ft_putendl(as);ft_putendl(b->dir_name);
	//if (ft_strcmp(as, bs) > 0)
	if (ft_strcmp(a->dir_name, b->dir_name) > 0)
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


void 			mergesort_dirs(t_dirs **headref, t_flags flags)
{
	t_dirs		*head;
	t_dirs		*a;
	t_dirs		*b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontbacksplit(head, &a, &b);
	mergesort_dirs(&a, flags);
	mergesort_dirs(&b, flags);
	if (flags & REVERSE_ORDER)
		*headref = sortedmerge_reverse(a, b);
	else
		*headref = sortedmerge(a, b);
}
