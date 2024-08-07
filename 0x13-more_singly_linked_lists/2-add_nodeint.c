#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - function that adds a new node at the
 * beginning of a listint_t list.
 * @head: Address of the first node of a list.
 * @n: Integer to insert into the new node.
 * 
 * Return: Address of the new element.
 **/
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;
	return (*head);
}
