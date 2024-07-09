#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - prints the sum of the two diagonals
 * of a square matrix of integers
 * @a: input square matrix
 * @size: size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int pri_sum = 0;
	int sec_sum = 0;
	int i;

	for (i = 0; i < size; i++)
	{
		pri_sum += a[i * size + i];
		sec_sum += a[i * size + (size - 1 - i)];
	}

	printf("%d, %d\n", pri_sum, sec_sum);
}
