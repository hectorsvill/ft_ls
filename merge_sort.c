#include "ft_ls.h"

/*
	split nodes into  front and back halves,
	and return two list with a and b.
	if list is odd extra node goes in front list.
	look up fast slow pointer strategy.
*/
static void 	frontbacksplit(t_ftls *source, t_ftls **frontref,
	t_ftls **backref)
{
	t_ftls		*fast;
	t_ftls		*slow;

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

static t_ftls	*sortedmerge(t_ftls *a, t_ftls *b)
{
	t_ftls		*result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->names, b->names) < 0)
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

void 			merge_sort(t_ftls **headref)
{
	t_ftls		*head;
	t_ftls		*a;
	t_ftls		*b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontbacksplit(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*headref = sortedmerge(a, b);
}
