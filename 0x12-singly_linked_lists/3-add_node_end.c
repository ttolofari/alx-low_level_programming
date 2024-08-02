#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - add new nodes to the end of the list
 * @head: supplied list
 * @str: string that needs to be duplicated
 * 
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	char *str_dup;
	list_t *last = *head;


	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	str_dup = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->str = str_dup;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (last->next)
		last = last->next;
	last->next = new;
	return (new);
}
