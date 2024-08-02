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
	list_t *new, *last;
	unsigned int i = 0;

	if (str == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	while (str[i])
		i++;
	new->len = i;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
	return (new);
}
