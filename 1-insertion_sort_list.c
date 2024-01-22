#include "sort.h"

/**
 *  insertion_sort_list - Sortd a doubly linked list in ascending order
 *
 *  @list: list containing data to bes sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *newNode, *insertion_point;

	current = *list;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		insertion_point = current->prev;
		newNode = current->next;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			insertion_point = insertion_point->prev;
		}
		if (insertion_point == NULL)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = *list;
			current->prev = NULL;
			(*list)->prev = current;
			*list = current;
		}
		else
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = insertion_point->next;
			current->prev = insertion_point;
			if (insertion_point->next != NULL)
				insertion_point->next->prev = current;
			insertion_point->next = current;
		}
		print_list(*list);
		current = newNode;
	}
}
