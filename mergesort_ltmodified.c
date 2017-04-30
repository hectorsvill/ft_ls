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
void reverse_files(t_files **head)
{
	t_files	*prev;
	t_files	*current;
	t_files *next;

	prev = NULL;
	next = NULL;
	current = *head;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void 			mergesort_ltmod(t_files **headref)
{
	t_files		*head;
	t_files		*a;
	t_files		*b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontbacksplit(head, &a, &b);
	mergesort_ltmod(&a);
	mergesort_ltmod(&b);
	*headref = sortedmerge(a, b);
	//reverse_files(headref);
	//printfileslist(*headref, 0);
	//headref needs to be backwards
	//its printing 1 2 3 instead of  3 2 1
}
