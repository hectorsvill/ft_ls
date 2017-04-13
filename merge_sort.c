#include "ft_ls.h"

#include <stdio.h>
#include <stdlib.h>
struct node
{
	char *data;
	struct node *next;
};

/*
	split nodes into  front and back halves,
	and return two list with a and b.
	if list is odd extra node goes in front list.
	look up fast slow pointer strategy.
*/
void frontbacksplit(struct node *source,  struct node **frontref, struct node **backref)
{
	struct node *fast;
	struct node *slow;

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

struct node *sortedmerge(struct node *a, struct node *b)
{
	struct node *result = NULL;
/* base case */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
/* pick either a or b, and recur */
	if (ft_strcmp(a->data, b->data) < 0)
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

void merge_sort(struct node **headref)
{
	struct node *head = *headref;
	struct node *a;
	struct node *b;

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

void push(struct node **head_ref, char *new_data)
{
	/* insert node at the begining if least*/

	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data =  new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void print_list(struct node *node)
{
	while (node)
	{
		printf("%s ", node->data);
		node = node->next;
	}
	printf("\n");
}

int main(void)
{
	//test above fx
	/* start with empy list */
	struct node *res = NULL;
	struct node *a =  NULL;

	/* unsorted list*/
	push(&a, "src");
	push(&a, "Makefile");
	push(&a, "apple");
	push(&a, "Art");
	push(&a, "down");
	push(&a, "four2");
	push(&a, "Voice");
	push(&a, "libft");
	push(&a, "reck");
	push(&a, "high");
	push(&a, "road");
	push(&a, "rich");
	push(&a, "one");

	print_list(a);

	/* sort the above created link list */

	merge_sort(&a);

	print_list(a);


	return (0);
}
