#include "sort.h"

/**
 *  insertion_sort_list - Sortd a doubly linked list in ascending order
 *
 *  @list: list containing data to bes sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *current, *newNode, *temp;

	sorted = NULL;
	current = *list;

	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}
	while (current != NULL)
	{
		newNode = current->next;
		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
			{
				sorted->prev = current;
			}
			sorted = current;
		}
		else
		{
			temp = sorted;
			while (temp->next != NULL && temp->next->n < current->n)
			{
				temp = temp->next;
			}
			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = current;
			temp->next = current;
			current->prev = temp;
		}
		print_list(*list);
		current = newNode;
	}
	*list = sorted;
}
