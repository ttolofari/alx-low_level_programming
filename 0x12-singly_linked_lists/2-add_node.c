#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: pointer to the list_t list
 * @str: resulting string
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *node;
	unsigned int i = 0;

	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);

	while (str[i])
	{
		i++;
	}

	node->str = strdup(str);
	node->len = i;
	node->next = (*head);
	(*head) = node;

	return (*head);
}

