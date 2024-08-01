#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_list - a function that prints all the
 * elements of a list_t list.
 * @h: singly linked list to print
 * 
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t i;

	for (i = 0; h; i++)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
	}
	return (i);
}
