#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: minimum range of values stored
 * @max: maximum range of values stored and number of elements
 *
 * Return: pointer to the new array
 */
int *array_range(int min, int max)
{
	int i, size; 
	int *mem;

	if (min > max)
	{
		return (NULL);
	}

	size = max - min + 1;
	
	mem = malloc(size * sizeof(int));
	
	if (mem == NULL)
	{
		return (NULL);
	}
	
	for (i = 0; min <= max; i++)
	{
		mem[i] = min++;
	}
	
	return (mem);
}
