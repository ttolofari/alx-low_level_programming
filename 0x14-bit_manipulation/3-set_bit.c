#include "main.h"
/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to number
 * @index: index to change
 * Return: 1 on success, -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (8 * sizeof(*n)) - 1)
		return (-1);
	*n = *n | (1 << index);
	return (1);
}
