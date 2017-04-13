#include "ft_ls.h"

/*
	split nodes into  front and back halves,
	and return two list with a and b.
	if list is odd extra node goes in front list.
	look up fast slow pointer strategy.
*/
void frontbacksplit(t_list *source,
		t_list **frontref, t_list **backref)
{
	t_list *fast;
	t_list *slow;

	if (source == NULL || source->next == NULL)
	{
		/* length < 2 cases */
		*frontref = source;
		*backref = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;

		/* Advance 'fast' two nodes, and advance 'slow' one node */
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		/* slow is before the midpoint in the list, so split in the two at that point */
		*frontref = source;
		*backref = slow->next;
		slow->next = NULL;
	}

}

t_list *sortedmerge(t_list *a, t_list *b)
{
	t_list *result = NULL;
/* base case */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
/* pick either a or b, and recur */
	if (ft_strcmp(a->content, b->content) < 0)
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

void merge_sort(t_list **headref)
{
	t_list *head;
	t_list *a;
	t_list *b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;

/* split head into a and b sublists */
	frontbacksplit(head, &a, &b);
/* recursively sort sublists */
	merge_sort(&a);
	merge_sort(&b);
/* answer = merge the two sorted lists together */
	*headref = sortedmerge(a, b);
}
