#include "lists.h"

/**
 * sum_dlistint - Sum of all the data (n) of a dlistint_t list.
 * @head: The head of the dlistint_t list.
 *
 * Return: The sum of all the data else return 0 if empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
