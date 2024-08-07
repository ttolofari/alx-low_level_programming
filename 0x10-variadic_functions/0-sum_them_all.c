#include "variadic_functions.h"

/**
 * sum_them_all - a function that returns
 * the sum of all its parameters.
 * @n: the number of parameters passed
 * 
 * Return: Always 0
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum;
	unsigned int i;
	va_list args;

	va_start(args, n);

	if (n == 0)
	{
		return (0);
	}

	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}

	va_end(args);

	return (sum);
}
