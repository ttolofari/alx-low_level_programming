#include <stdio.h>
#include "lists.h"
#include <string.h>
/**
 * print_listint - prints all the elements
 * of a listint_t list
 * @h: singly linked list print
 * 
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	
	return (i);
}
