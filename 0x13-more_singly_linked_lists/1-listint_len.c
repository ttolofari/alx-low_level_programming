#include <stdio.h>
#include "lists.h"
#include <string.h>
/**
 * listint_len - returns the number of elements
 * in a listint_t list
 * @h: singly linked list print
 * 
 * Return: the number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t i;

	for (i = 0; h; i++)
		h = h->next;
	return (i);
}
