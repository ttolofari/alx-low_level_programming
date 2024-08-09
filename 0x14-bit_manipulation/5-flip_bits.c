#include "main.h"
#include <stdio.h>
/**
 * flip_bits - number of bits you would need to
 * flip to get from one number to another.
 * @n: base number
 * @m: number to transform to
 * Return: number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, result;

	result = 0;
	for (i = 8 * sizeof(n) - 1; i >= 0; i--)
		if (((n ^ m) >> i) & 1)
			result++;
	return (result);
}
