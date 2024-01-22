#include "sort.h"

/**
 * inserNode - Inserts a node
 *
 * @head: Pointer to the first node of the  list
 * @data: Element inside the list
 */

void insertNode(listint_t **head, const int data)
{
	listint_t *newNode, *current;

	*newNode = malloc(sizeof(*node));

	newNode->n = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		current = *head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
	}
}
