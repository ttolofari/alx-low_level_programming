#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 * @head: Double pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp, *current;

	if (head == NULL)
		return;
	current = *head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}
