#include <stdlib.h>
#include "main.h"
/**
 * *_calloc - allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: size of each element
 *
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *alloc;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	alloc = malloc(nmemb * size);
	if (alloc == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < nmemb * size; i++)
	{
		*(alloc + i) = 0;
	}
	return ((void *)alloc);
}

