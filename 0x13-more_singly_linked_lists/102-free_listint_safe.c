#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Double pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	size_t i;
	listint_t *temp;

	if (h == NULL || *h == NULL)
		return (0);
	while (*h)
	{
		i = *h - (*h)->next;
		if (i > 0)
		{
			temp = (*h)->next;
			*h = temp;
			count++;
		}
		else
		{
			*h = NULL;
			count++;
			break;
		}
	}

	*h = NULL;

	return (count);
}
