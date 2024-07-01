#include "main.h"

/**
 * swap_int(int *a, int *b) - a function that swaps the values
 * of two integers
 * @a : first input integer
 * @b : second input integer
 */

void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
