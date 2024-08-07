#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list
 * and returns the head node's data (n).
 * @head: Double pointer to the head of the list.
 *
 * Return: The data (n) of the head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int i;
	listint_t *current, *temp;

	if (head == NULL)
		return (0);
	temp = current = *head;
	if (*head)
	{
		i = current->n;
		*head = current->next;
		free(temp);
	}
	else
		i = 0;
	return (i);
}
