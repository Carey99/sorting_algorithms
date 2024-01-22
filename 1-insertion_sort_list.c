#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * @list: Double pointer to the head of the linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swapNode, *nextSwap;

	if (list == NULL || *list == NULL)
		return;
	swapNode = (*list)->next;
	while (swapNode != NULL)
	{
		nextSwap = swapNode->next;
		while (swapNode->prev != NULL && swapNode->prev->n > swapNode->n)
		{
			swapNode->prev->next = swapNode->next;
			if (swapNode->next != NULL)
				swapNode->next->prev = swapNode->prev;
			swapNode->next = swapNode->prev;
			swapNode->prev = swapNode->next->prev;
			swapNode->next->prev = swapNode;
			if (swapNode->prev == NULL)
				*list = swapNode;
			else
				swapNode->prev->next = swapNode;
			print_list(*list);
		}
		swapNode = nextSwap;
	}
}
