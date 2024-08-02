#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * list_len - provides number of nodes in a link list
 * @h: singly linked list
 *
 * Return: number of elements in a linked list
 */
size_t list_len(const list_t *h)
{
	unsigned int count = 0;
	const list_t *val;

	val = h;

	while (val != NULL)
	{
		count++;
		val = val->next;
	}

	return (count);
}
