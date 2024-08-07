#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data
 * (n) in a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The sum of all the data (n) in the list,
 * or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int tot = 0;

	while (head != NULL)
	{
		tot += head->n;
		head = head->next;
	}

	return (tot);
}
